#include <error.h>
#include <helper.h>
#include <visitor.h>

namespace ch2c {

antlrcpp::Any Visitor::visitFile(BasicParser::FileContext* ctx) {
  printHeader();

  auto& rules = ctx->children;

  for (int i = 0; i < rules.size(); i++) {
    if (antlrcpp::is<BasicParser::ExprStmtContext*>(rules[i])) {
      this->visitExprStmt(
          dynamic_cast<BasicParser::ExprStmtContext*>(rules[i]));
    } else if (antlrcpp::is<BasicParser::FuncDefContext*>(rules[i])) {
      functionContext fCtx =
          this->visitFuncDef(
                  dynamic_cast<BasicParser::FuncDefContext*>(rules[i]))
              .as<functionContext>();
      if (fCtx.valid) {
        fCtx.type.functionPrintName = fCtx.type.functionName;
        insertFunction(fCtx.type);
        printFunctionSignature(fCtx.type, false);
        currentFunction = &fCtx.type;
        this->visitBlckStmt(fCtx.blckStmt);
        currentFunction = nullptr;
      }
    } else if (antlrcpp::is<BasicParser::ExtFuncDeclContext*>(rules[i])) {
      this->visitExtFuncDecl(
          dynamic_cast<BasicParser::ExtFuncDeclContext*>(rules[i]));
    } else if (antlrcpp::is<BasicParser::RecDeclContext*>(rules[i])) {
      this->visitRecDecl(dynamic_cast<BasicParser::RecDeclContext*>(rules[i]));
    } else if (antlrcpp::is<BasicParser::VarDefContext*>(rules[i])) {
      this->visitVarDef(dynamic_cast<BasicParser::VarDefContext*>(rules[i]));
    }
  }

  if (Error.isError) {
    return false;
  } else {
    return false;
  }
}

antlrcpp::Any Visitor::visitRecDecl(BasicParser::RecDeclContext* ctx) {
  std::string name = ctx->IDENTIFIER()->getText();
  if (!checkUsableIdentifier(name)) {
    Error.addError(
        DetailedError("NameError", ctx->getStart()->getLine(),
                      ctx->getStart()->getCharPositionInLine(),
                      "Already declared a variable with this name."));
    return nullptr;
  }
  recordType record;
  record.name = name;
  record.typeIndex = recordsList.size() + Visitor::BUILT_IN_TYPE_COUNT;
  for (int i = 0; i < ctx->varParam().size(); i++) {
    variableDeclaration var =
        this->visitVarParam(ctx->varParam(i)).as<variableDeclaration>();
    if (var.type == -1) {
      continue;
    }
    if (record.members.find(var.name) == record.members.end()) {
      record.members.insert(
          make_pair(var.name, variableType{var.type, var.name}));
    } else {
      Error.addError(
          DetailedError("NameError", var.line, var.column,
                        "Already declared a member with this name."));
    }
  }
  printRecord(record);
  std::vector<std::pair<std::string, BasicParser::BlckStmtContext*>> stmts;
  for (int i = 0; i < ctx->funcDef().size(); i++) {
    functionContext func =
        this->visitFuncDef(ctx->funcDef(i)).as<functionContext>();
    if (func.valid) {
      if (record.methods.find(func.type.functionName) != record.methods.end()) {
        Error.addError(
            DetailedError("NameError", ctx->funcDef(i)->getStart()->getLine(),
                          ctx->funcDef(i)->getStart()->getCharPositionInLine(),
                          "Already declared a method with this name."));
      } else if (record.members.find(func.type.functionName) !=
                 record.members.end()) {
        Error.addError(
            DetailedError("NameError", ctx->funcDef(i)->getStart()->getLine(),
                          ctx->funcDef(i)->getStart()->getCharPositionInLine(),
                          "Already declared a member with this name."));
      } else {
        func.type.functionPrintName = name + "__" + func.type.functionName;
        record.methods.insert({func.type.functionName, func.type});
        stmts.push_back({func.type.functionName, func.blckStmt});
      }
    }
  }
  insertRecord(record);
  for (int i = 0; i < stmts.size(); i++) {
    currentRecord = &recordsList[recordsList.size() - 1];
    currentFunction = &(currentRecord->methods.find(stmts[i].first)->second);
    printMethodSignature(record, record.methods.find(stmts[i].first)->second);
    this->visitBlckStmt(stmts[i].second);
    currentFunction = nullptr;
    currentRecord = nullptr;
  }
  return nullptr;
}

antlrcpp::Any Visitor::visitFuncDef(BasicParser::FuncDefContext* ctx) {
  functionType function =
      this->visitFuncSignature(ctx->funcSignature()).as<functionType>();
  if (!checkUsableIdentifier(function.functionName)) {
    Error.addError(DetailedError("NameError", ctx->getStart()->getLine(),
                                 ctx->getStart()->getCharPositionInLine(),
                                 "Function Name is already being used."));
    return functionContext{std::move(function), ctx->blckStmt(), false};
  }
  if (function.returnType == -1) {
    return functionContext{std::move(function), ctx->blckStmt(), false};
  } else {
    return functionContext{std::move(function), ctx->blckStmt(), true};
  }
}

antlrcpp::Any Visitor::visitBlckStmt(BasicParser::BlckStmtContext* ctx) {
  outFile << " {\n";
  auto& rules = ctx->children;
  for (int i = 1; i < rules.size() - 1; i++) {
    if (antlrcpp::is<BasicParser::ExprStmtContext*>(rules[i])) {
      this->visitExprStmt(
          dynamic_cast<BasicParser::ExprStmtContext*>(rules[i]));
    } else if (antlrcpp::is<BasicParser::VarDefContext*>(rules[i])) {
      this->visitVarDef(dynamic_cast<BasicParser::VarDefContext*>(rules[i]));
    } else if (antlrcpp::is<BasicParser::RetStmtContext*>(rules[i])) {
      this->visitRetStmt(dynamic_cast<BasicParser::RetStmtContext*>(rules[i]));
    }
  }
  outFile << "}\n";
  return nullptr;
}

antlrcpp::Any Visitor::visitRetStmt(BasicParser::RetStmtContext* ctx) {
  expressionData expr = this->visitExpr(ctx->expr()).as<expressionData>();
  if (expr.type == -1) {
    return nullptr;
  }
  if (expr.type != currentFunction->returnType) {
    Error.addError(DetailedError("TypeError", ctx->getStart()->getLine(),
                                 ctx->getStart()->getCharPositionInLine(),
                                 "Wrong Return Type for given function %s.",
                                 currentFunction->functionName.c_str()));
  } else {
    printExpression("return " + expr.expression);
  }
  return nullptr;
}

antlrcpp::Any Visitor::visitExtFuncDecl(BasicParser::ExtFuncDeclContext* ctx) {
  functionType function =
      this->visitFuncSignature(ctx->funcSignature()).as<functionType>();
  if (function.returnType != -1) {
    function.functionPrintName = ctx->IDENTIFIER() == nullptr
                                     ? function.functionName
                                     : ctx->IDENTIFIER()->getText();
    if (!checkUsableIdentifier(function.functionName)) {
      Error.addError(DetailedError("NameError", ctx->getStart()->getLine(),
                                   ctx->getStart()->getCharPositionInLine(),
                                   "Function Name is already being used."));
    }
    insertFunction(function);
    printFunctionSignature(function, true);
  }
  return nullptr;
}

antlrcpp::Any Visitor::visitFuncSignature(
    BasicParser::FuncSignatureContext* ctx) {
  functionType function;
  function.returnType = -1;
  int line = ctx->getStart()->getLine();
  int column = ctx->getStart()->getCharPositionInLine();
  int returnType = ctx->typeDecl() == nullptr
                       ? 0
                       : this->visitTypeDecl(ctx->typeDecl()).as<Type>();
  if (returnType == -1) {
    this->Error.addError(DetailedError("TypeError", line, column,
                                       "Return type is not a valid type."));
    return function;
  }

  std::string name = ctx->IDENTIFIER()->getText();
  function.functionName = name;
  std::vector<BasicParser::VarParamContext*> params;
  if (ctx->argList() != nullptr) {
    params = ctx->argList()->varParam();
  }
  for (int i = 0; i < params.size(); i++) {
    variableDeclaration variable =
        this->visitVarParam(params[i]).as<variableDeclaration>();
    if (!checkUsableName(variable.name) ||
        function.localVariables.find(variable.name) !=
            function.localVariables.end()) {
      Error.addError(DetailedError("NameError", variable.line, variable.column,
                                   "Parameter name is not valid."));
      return function;
    } else {
      function.parameterList.push_back(
          variableType{variable.type, variable.name});
      function.localVariables.insert(
          std::make_pair(variable.name, variable.type));
    }
  }
  function.returnType = returnType;
  return function;
}

antlrcpp::Any Visitor::visitStatements(BasicParser::StatementsContext* ctx) {
  if (ctx->exprStmt() != nullptr) {
    this->visitExprStmt(ctx->exprStmt());
  } else {
    this->visitBlckStmt(ctx->blckStmt());
  }
}

antlrcpp::Any Visitor::visitExprStmt(BasicParser::ExprStmtContext* ctx) {
  printExpression(this->visitExpr(ctx->expr()).as<expressionData>().expression);
  return nullptr;
}

// Deal with expressions
antlrcpp::Any Visitor::visitExpr(BasicParser::ExprContext* ctx) {
  if (antlrcpp::is<BasicParser::CastContext*>(ctx)) {
    return this->visitCast(dynamic_cast<BasicParser::CastContext*>(ctx));
  } else if (antlrcpp::is<BasicParser::LitExprContext*>(ctx)) {
    return this->visitLiteral(
        dynamic_cast<BasicParser::LitExprContext*>(ctx)->literal());
  } else if (antlrcpp::is<BasicParser::LvalExprContext*>(ctx)) {
    return this->visitLvalExpr(
        dynamic_cast<BasicParser::LvalExprContext*>(ctx));
  } else if (antlrcpp::is<BasicParser::MulContext*>(ctx)) {
    return this->visitMul(dynamic_cast<BasicParser::MulContext*>(ctx));
  } else if (antlrcpp::is<BasicParser::AddContext*>(ctx)) {
    return this->visitAdd(dynamic_cast<BasicParser::AddContext*>(ctx));
  } else if (antlrcpp::is<BasicParser::AsgContext*>(ctx)) {
    return this->visitAsg(dynamic_cast<BasicParser::AsgContext*>(ctx));
  }
}

antlrcpp::Any Visitor::visitMul(BasicParser::MulContext* ctx) {
  expressionData lhs = this->visitExpr(ctx->expr(0)).as<expressionData>();
  expressionData rhs = this->visitExpr(ctx->expr(1)).as<expressionData>();

  if (lhs.type == -1 || rhs.type == -1) {
    return expressionData{-1, "", false};
  }

  if (lhs.type < 1 || lhs.type > 11 || rhs.type < 1 || rhs.type > 11) {
    Error.addError(DetailedError(
        "TypeError", ctx->op->getLine(), ctx->op->getCharPositionInLine(),
        "%s operator is not supported for %s and %s expressions.",
        ctx->op->getText().c_str(), getName(lhs.type).c_str(),
        getName(rhs.type).c_str()));
    return expressionData{-1, "", false};
  } else {
    return expressionData{
        std::max(lhs.type, rhs.type),
        lhs.expression + " " + ctx->op->getText() + " " + rhs.expression,
        false};
  }
}

antlrcpp::Any Visitor::visitAdd(BasicParser::AddContext* ctx) {
  expressionData lhs = this->visitExpr(ctx->expr(0)).as<expressionData>();
  expressionData rhs = this->visitExpr(ctx->expr(1)).as<expressionData>();

  if (lhs.type == -1 || rhs.type == -1) {
    return expressionData{-1, "", false};
  }

  if (lhs.type < 1 || lhs.type > 11 || rhs.type < 1 || rhs.type > 11) {
    Error.addError(DetailedError(
        "TypeError", ctx->op->getLine(), ctx->op->getCharPositionInLine(),
        "%s operator is not supported for %s and %s expressions.",
        ctx->op->getText().c_str(), getName(lhs.type).c_str(),
        getName(rhs.type).c_str()));
    return expressionData{-1, "", false};
  } else {
    return expressionData{
        std::max(lhs.type, rhs.type),
        lhs.expression + " " + ctx->op->getText() + " " + rhs.expression,
        false};
  }
}

antlrcpp::Any Visitor::visitLiteral(BasicParser::LiteralContext* ctx) {
  if (antlrcpp::is<BasicParser::StringContext*>(ctx)) {
    return expressionData{12, ctx->getText(), false};
  } else if (antlrcpp::is<BasicParser::BoolTContext*>(ctx)) {
    return expressionData{1, TRUE_NAME, false};
  } else if (antlrcpp::is<BasicParser::BoolFContext*>(ctx)) {
    return expressionData{1, FALSE_NAME, false};
  } else if (antlrcpp::is<BasicParser::IntDecContext*>(ctx)) {
    return expressionData{8, numLiteral(ctx->getText()), false};
  } else if (antlrcpp::is<BasicParser::IntHexContext*>(ctx)) {
    return expressionData{8, numLiteral(ctx->getText()), false};
  } else if (antlrcpp::is<BasicParser::IntOctContext*>(ctx)) {
    return expressionData{8, numLiteral(ctx->getText()), false};
  } else if (antlrcpp::is<BasicParser::RealContext*>(ctx)) {
    return expressionData{10, numLiteral(ctx->getText()), false};
  }
}

antlrcpp::Any Visitor::visitCast(BasicParser::CastContext* ctx) {
  expressionData expr = this->visitExpr(ctx->expr()).as<expressionData>();

  Type type = this->visitTypeDecl(ctx->typeDecl()).as<Type>();

  if (expr.type == -1 || type == -1) {
    return expressionData{-1, "", false};
  }

  if (expr.type < 1 || expr.type > 11) {
    Error.addError(DetailedError("TypeError", ctx->getStart()->getLine(),
                                 ctx->getStart()->getCharPositionInLine(),
                                 "Cannot cast expression of type %s.",
                                 getName(expr.type).c_str()));
    return expressionData{-1, "", false};
  } else if (type < 1 || type > 11) {
    Error.addError(DetailedError("TypeError", ctx->getStart()->getLine(),
                                 ctx->getStart()->getCharPositionInLine(),
                                 "Cannot cast expression to the given type %s.",
                                 getName(type).c_str()));
    return expressionData{-1, "", false};
  } else {
    return expressionData{
        type, "(" + getPrintName(type) + ")(" + expr.expression + ')', false};
  }
}

antlrcpp::Any Visitor::visitAsg(BasicParser::AsgContext* ctx) {
  expressionData value = this->visitValue(ctx->lVal()).as<expressionData>();
  if (value.type == -1) {
    return expressionData{-1, "", false};
  }
  if (!value.assignable) {
    Error.addError(DetailedError("ValueError", ctx->getStart()->getLine(),
                                 ctx->getStart()->getCharPositionInLine(),
                                 "Invalid assignment to expression."));
    return expressionData{-1, "", false};
  } else {
    expressionData expr = this->visitExpr(ctx->expr()).as<expressionData>();
    if (expr.type == -1) {
      return expressionData{-1, "", false};
    }
    if (expr.type != value.type) {
      if (expr.type < 1 || value.type < 1 || expr.type > 11 ||
          value.type > 11) {
        Error.addError(DetailedError("TypeError", ctx->getStart()->getLine(),
                                     ctx->getStart()->getCharPositionInLine(),
                                     "Invalid assignment to value of type %s "
                                     "by expression of type %s.",
                                     getName(value.type).c_str(),
                                     getName(expr.type).c_str()));
        return expressionData{-1, "", false};
      } else {
        return expressionData{
            value.type, value.expression + " = " + expr.expression, false};
      }
    } else {
      return expressionData{value.type,
                            value.expression + " = " + expr.expression, false};
    }
  }
}

antlrcpp::Any Visitor::visitLvalExpr(BasicParser::LvalExprContext* ctx) {
  expressionData value = this->visitValue(ctx->lVal()).as<expressionData>();
  return expressionData{value.type, value.expression, value.assignable};
}

antlrcpp::Any Visitor::visitValue(BasicParser::LValContext* ctx) {
  if (antlrcpp::is<BasicParser::ThisContext*>(ctx)) {
    if (currentRecord == nullptr) {
      Error.addError(DetailedError("TypeError", ctx->getStart()->getLine(),
                                   ctx->getStart()->getCharPositionInLine(),
                                   "`this` is not valid outside of a method."));
      return expressionData{-1, "", false};
    } else {
      return expressionData{currentRecord->typeIndex, "(*this)", false};
    }
  } else if (antlrcpp::is<BasicParser::IdenContext*>(ctx)) {
    std::string name = dynamic_cast<BasicParser::IdenContext*>(ctx)->getText();
    if (checkExistVariable(name)) {
      return expressionData{getVariableType(name), name, true};
    } else {
      Error.addError(DetailedError("TypeError", ctx->getStart()->getLine(),
                                   ctx->getStart()->getCharPositionInLine(),
                                   "This variable does not exist."));
      return expressionData{-1, "", false};
    }
  } else if (antlrcpp::is<BasicParser::MemberContext*>(ctx)) {
    BasicParser::MemberContext* member =
        dynamic_cast<BasicParser::MemberContext*>(ctx);
    expressionData expr = this->visitValue(member->lVal()).as<expressionData>();
    int type = expr.type;
    if (type == -1) {
      return expressionData{-1, "", false};
    }
    if (type < Visitor::BUILT_IN_TYPE_COUNT) {
      Error.addError(
          DetailedError("TypeError", member->getStart()->getLine(),
                        member->getStart()->getCharPositionInLine(),
                        "Cannot access field for a non-record type."));
      return expressionData{-1, "", false};
    } else {
      const recordType& record = getRecord(type);
      std::string field = member->IDENTIFIER()->getText();
      if (record.members.find(field) == record.members.end()) {
        Error.addError(
            DetailedError("NameError", member->getStart()->getLine(),
                          member->getStart()->getCharPositionInLine(),
                          "No such member exists for %s record type.",
                          getName(type).c_str()));
        return expressionData{-1, "", false};
      } else {
        return expressionData{
            record.members.find(field)->second.typeIndex,
            expr.expression + '.' + record.members.find(field)->second.name,
            true};
      }
    }
  } else if (antlrcpp::is<BasicParser::MethodContext*>(ctx)) {
    BasicParser::MethodContext* method =
        dynamic_cast<BasicParser::MethodContext*>(ctx);
    expressionData expr = this->visitValue(method->lVal()).as<expressionData>();
    int type = expr.type;
    if (type == -1) {
      return expressionData{-1, "", false};
    }
    if (type < Visitor::BUILT_IN_TYPE_COUNT) {
      Error.addError(
          DetailedError("TypeError", method->getStart()->getLine(),
                        method->getStart()->getCharPositionInLine(),
                        "Cannot access method for a non-record type."));
      return expressionData{-1, "", false};
    } else {
      const recordType& record = getRecord(type);
      std::string func = method->IDENTIFIER()->getText();
      if (record.methods.find(func) == record.methods.end()) {
        Error.addError(
            DetailedError("NameError", method->getStart()->getLine(),
                          method->getStart()->getCharPositionInLine(),
                          "No such method exists for %s record type.",
                          getName(type).c_str()));
        return expressionData{-1, "", false};
      } else {
        const functionType& function = record.methods.find(func)->second;
        BasicParser::FuncCallContext* functionCall = method->funcCall();
        std::string expression =
            this->functionHelper(function, functionCall).as<std::string>();
        if (expression.empty()) {
          return expressionData{-1, "", false};
        } else {
          return expressionData{
              function.returnType,
              function.functionPrintName + "(&(" + expr.expression +
                  (expression.length() > 1 ? ")," : ")") + expression,
              false};
        }
      }
    }
  } else if (antlrcpp::is<BasicParser::CallContext*>(ctx)) {
    BasicParser::CallContext* call =
        dynamic_cast<BasicParser::CallContext*>(ctx);
    if (checkExistFunction(call->lVal()->getText())) {
      functionType& function =
          functionsList.find(call->lVal()->getText())->second;
      BasicParser::FuncCallContext* functionCall = call->funcCall();
      std::string expression =
          this->functionHelper(function, functionCall).as<std::string>();
      if (expression.empty()) {
        return expressionData{-1, "", false};
      } else {
        return expressionData{function.returnType,
                              function.functionPrintName + "(" + expression,
                              false};
      }
    } else {
      Error.addError(DetailedError("NameError", ctx->getStart()->getLine(),
                                   ctx->getStart()->getCharPositionInLine(),
                                   "No such function exists."));
      return expressionData{-1, "", false};
    }
  } else {
    return this->visitExpr(
        dynamic_cast<BasicParser::PExprContext*>(ctx)->expr());
  }
}

antlrcpp::Any Visitor::functionHelper(
    const functionType& function, BasicParser::FuncCallContext* functionCall) {
  if (functionCall->funcParams() == nullptr &&
      function.parameterList.size() > 0) {
    Error.addError(
        DetailedError("CallError", functionCall->getStart()->getLine(),
                      functionCall->getStart()->getCharPositionInLine(),
                      "No arguments supplied. Expected %llu arguments.",
                      function.parameterList.size()));
    return std::string("");
  } else if (function.parameterList.size() > 0 &&
             function.parameterList.size() >
                 functionCall->funcParams()->expr().size()) {
    Error.addError(DetailedError(
        "CallError", functionCall->getStart()->getLine(),
        functionCall->getStart()->getCharPositionInLine(),
        "Too few arguments supplied. Expected %llu arguments. Got %lld.",
        function.parameterList.size(),
        functionCall->funcParams()->expr().size()));
    return std::string("");
  } else if (function.parameterList.size() > 0 &&
             function.parameterList.size() <
                 functionCall->funcParams()->expr().size()) {
    Error.addError(DetailedError(
        "CallError", functionCall->getStart()->getLine(),
        functionCall->getStart()->getCharPositionInLine(),
        "Too many arguments supplied. Expected %llu arguments. Got %lld.",
        function.parameterList.size(),
        functionCall->funcParams()->expr().size()));
    return std::string("");
  } else {
    std::string expression;
    for (int i = 0; i < function.parameterList.size(); i++) {
      expressionData expr =
          this->visitExpr(functionCall->funcParams()->expr(i));
      if (expr.type == -1) {
        return std::string("");
      } else {
        if (expr.type != function.parameterList[i].typeIndex) {
          Error.addError(DetailedError(
              "TypeError",
              functionCall->funcParams()->expr(i)->getStart()->getLine(),
              functionCall->funcParams()
                  ->expr(i)
                  ->getStart()
                  ->getCharPositionInLine(),
              "Type Mismatch between expected argument and supplied "
              "expression. Expected %s, got %s.",
              getName(function.parameterList[i].typeIndex).c_str(),
              getName(expr.type).c_str()));
          return std::string("");
        } else {
          expression += i >= 1 ? ", " : "";
          expression += expr.expression;
        }
      }
    }
    expression += ")";
    return expression;
  }
}

// Dealing with Variable Declaration and Defination
antlrcpp::Any Visitor::visitTypeDecl(BasicParser::TypeDeclContext* ctx) {
  return this->visitVarType(ctx->varType());
}

antlrcpp::Any Visitor::visitVarParam(BasicParser::VarParamContext* ctx) {
  return variableDeclaration{this->visitTypeDecl(ctx->typeDecl()).as<Type>(),
                             ctx->IDENTIFIER()->getText(),
                             ctx->getStart()->getLine(),
                             ctx->getStart()->getCharPositionInLine()};
}

antlrcpp::Any Visitor::visitVarType(BasicParser::VarTypeContext* ctx) {
  if (ctx->primTypes()) {
    return Visitor::BUILT_IN_TYPES_INDEX.find(ctx->primTypes()->getText())
        ->second;
  } else {
    auto x = typeMap.find(ctx->IDENTIFIER()->getText());
    if (x != typeMap.end()) {
      return static_cast<Type>(x->second);
    } else {
      Error.addError(DetailedError("TypeError", ctx->getStart()->getLine(),
                                   ctx->getStart()->getCharPositionInLine(),
                                   "%s is not a valid type.",
                                   ctx->IDENTIFIER()->getText().c_str()));
      return static_cast<Type>(-1);
    }
  }
}

antlrcpp::Any Visitor::visitVarDecl(BasicParser::VarDeclContext* ctx) {
  Type type;
  expressionData expr;
  if (ctx->typeDecl() == nullptr) {
    expr = this->visitExpr(ctx->expr()).as<expressionData>();
    type = expr.type;
  } else {
    type = this->visitTypeDecl(ctx->typeDecl()).as<Type>();
    if (ctx->expr() != nullptr) {
      expr = this->visitExpr(ctx->expr()).as<expressionData>();
    } else {
      expr.type = type;
      expr.expression = "";
    }
  }
  if (type == 0) {
    Error.addError(DetailedError("TypeError", ctx->getStart()->getLine(),
                                 ctx->getStart()->getCharPositionInLine(),
                                 "Variables of type void is not allowed."));
    return std::vector<variableDefinition>();
  }
  if (type == -1 || expr.type == -1) {
    return std::vector<variableDefinition>();
  }
  if (type != expr.type) {
    Error.addError(DetailedError("ValueError", ctx->getStart()->getLine(),
                                 ctx->getStart()->getCharPositionInLine(),
                                 "Invalid initialization of variable of type "
                                 "%s by expression of type %s.",
                                 getName(type).c_str(),
                                 getName(expr.type).c_str()));
    return std::vector<variableDefinition>();
  } else {
    for (int i = 0; i < ctx->IDENTIFIER().size(); i++) {
      for (int j = i + 1; j < ctx->IDENTIFIER().size(); j++) {
        if (!checkUsableIdentifier(ctx->IDENTIFIER(i)->getText()) ||
            ctx->IDENTIFIER(i)->getText() == ctx->IDENTIFIER(j)->getText()) {
          Error.addError(
              DetailedError("NameError", ctx->getStart()->getLine(),
                            ctx->getStart()->getCharPositionInLine(),
                            "Attempt to declare already declared variable."));
          return std::vector<variableDefinition>();
        }
      }
    }
    std::vector<variableDefinition> variables;
    for (int i = 0; i < ctx->IDENTIFIER().size(); i++) {
      variables.push_back(variableDefinition{
          type, ctx->IDENTIFIER(i)->getText(), expr.expression});
    }
    for (int i = 1; i < ctx->IDENTIFIER().size(); i++) {
      variables[i].initializer = variables[0].name;
    }
    return variables;
  }
}

antlrcpp::Any Visitor::visitVarDef(BasicParser::VarDefContext* ctx) {
  for (int i = 0; i < ctx->varDecl().size(); i++) {
    std::vector<variableDefinition> variables =
        this->visitVarDecl(ctx->varDecl(i))
            .as<std::vector<variableDefinition>>();
    for (int i = 0; i < variables.size(); i++) {
      insertVariable(variables[i].name, variables[i].type);
    }
    printVariables(variables);
  }
  return nullptr;
}

}  // namespace ch2c