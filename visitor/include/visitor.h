#include <antlr4-runtime/antlr4-runtime.h>
#include <data.h>
#include <definitions.h>
#include <grammar/BasicParser.h>
#include <grammar/BasicParserBaseVisitor.h>

#include <map>
#include <sstream>
#include <string>
#include <vector>

#ifndef CH_VISITOR_H
#define CH_VISITOR_H CH_VISITOR_H

namespace ch2c {

class Visitor : public BasicParserBaseVisitor {
 public:
  Visitor() : BasicParserBaseVisitor() {
    Error.isError = false;

    currentFunction = nullptr;
    currentRecord = nullptr;
  }

  static struct visitorError {
    bool isError;
    void setError() { isError = true; }
    std::vector<std::string> Errors;
    void addError(const std::string& err) {
      Errors.push_back(err);
      setError();
    }
  } Error;

  static std::size_t BUILT_IN_TYPE_COUNT;

  static std::string TRUE_NAME;
  static std::string FALSE_NAME;

  static std::vector<std::string> BUILT_IN_TYPES;
  static std::vector<std::string> BUILT_IN_TYPES_PRINT;
  static std::map<std::string, Type> BUILT_IN_TYPES_INDEX;

  std::map<std::string, Type> typeMap;  // Map from type to index

  std::map<std::string, Type> globalVariables;  // Map of Global Variables

  functionType* currentFunction;  // nullptr indicates that we are
                                  // not parsing functions now.

  recordType*
      currentRecord;  // nullptr indicates that we are not parsing records now.

  std::vector<recordType> recordsList;  // Map of defined Records

  std::map<std::string, functionType>
      functionsList;  // Map of defined functions

  std::stringstream outFile;

  bool checkUsableIdentifier(const std::string& name);

  bool checkUsableName(const std::string& name);

  bool checkExistFunction(const std::string& name);

  bool checkExistVariable(const std::string& name);

  void insertVariable(const std::string& name, Type type);

  void insertFunction(const functionType& function);

  bool checkExistRecord(const std::string& name);

  const recordType& getRecord(const std::string& name);

  const recordType& getRecord(Type type);

  void insertRecord(const recordType& record);

  Type getType(const std::string& name);

  const std::string& getPrintName(Type type);

  const std::string& getName(Type type);

  Type getVariableType(const std::string& name);

  // Print Functions

  void printHeader();

  void printFunctionSignature(const functionType& function, bool semicolon);

  void printVariables(const std::vector<variableDefinition>& variables);

  void printRecord(const recordType& variables);

  void printExpression(const std::string& expression);

  void printMethodSignature(const recordType& record,
                            const functionType& function);

  virtual antlrcpp::Any visitFile(BasicParser::FileContext* context) override;
  virtual antlrcpp::Any visitStatements(
      BasicParser::StatementsContext* context) override;
  virtual antlrcpp::Any visitExprStmt(
      BasicParser::ExprStmtContext* context) override;
  virtual antlrcpp::Any visitExpr(BasicParser::ExprContext* context);
  virtual antlrcpp::Any visitVarType(
      BasicParser::VarTypeContext* context) override;
  virtual antlrcpp::Any visitTypeDecl(
      BasicParser::TypeDeclContext* context) override;
  virtual antlrcpp::Any visitVarParam(
      BasicParser::VarParamContext* context) override;
  virtual antlrcpp::Any visitVarDecl(
      BasicParser::VarDeclContext* context) override;
  virtual antlrcpp::Any visitVarDef(
      BasicParser::VarDefContext* context) override;

  virtual antlrcpp::Any visitAdd(BasicParser::AddContext* context) override;
  virtual antlrcpp::Any visitMul(BasicParser::MulContext* context) override;
  virtual antlrcpp::Any visitAsg(BasicParser::AsgContext* context) override;
  virtual antlrcpp::Any visitCast(BasicParser::CastContext* context) override;
  virtual antlrcpp::Any visitLvalExpr(
      BasicParser::LvalExprContext* context) override;
  virtual antlrcpp::Any visitLiteral(BasicParser::LiteralContext* context);
  virtual antlrcpp::Any visitValue(BasicParser::LValContext* context);
  virtual antlrcpp::Any visitFuncDef(
      BasicParser::FuncDefContext* context) override;
  virtual antlrcpp::Any visitExtFuncDecl(
      BasicParser::ExtFuncDeclContext* context) override;
  virtual antlrcpp::Any visitFuncSignature(
      BasicParser::FuncSignatureContext* context) override;
  virtual antlrcpp::Any visitBlckStmt(
      BasicParser::BlckStmtContext* context) override;
  virtual antlrcpp::Any visitRetStmt(
      BasicParser::RetStmtContext* context) override;

  virtual antlrcpp::Any functionHelper(const functionType& function,
                                       BasicParser::FuncCallContext* context);
  virtual antlrcpp::Any visitRecDecl(
      BasicParser::RecDeclContext* context) override;
};

}  // namespace ch2c

#endif