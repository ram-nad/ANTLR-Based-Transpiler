
// Generated from BasicParser.g4 by ANTLR 4.8

#pragma once

#include <antlr4-runtime/antlr4-runtime.h>
#include <grammar/BasicParser.h>

namespace ch2c {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by BasicParser.
 */
class BasicParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
 public:
  /**
   * Visit parse trees produced by BasicParser.
   */
  virtual antlrcpp::Any visitFile(BasicParser::FileContext *context) = 0;

  virtual antlrcpp::Any visitStatements(
      BasicParser::StatementsContext *context) = 0;

  virtual antlrcpp::Any visitRetStmt(BasicParser::RetStmtContext *context) = 0;

  virtual antlrcpp::Any visitBlckStmt(
      BasicParser::BlckStmtContext *context) = 0;

  virtual antlrcpp::Any visitExprStmt(
      BasicParser::ExprStmtContext *context) = 0;

  virtual antlrcpp::Any visitPrimTypes(
      BasicParser::PrimTypesContext *context) = 0;

  virtual antlrcpp::Any visitVarType(BasicParser::VarTypeContext *context) = 0;

  virtual antlrcpp::Any visitTypeDecl(
      BasicParser::TypeDeclContext *context) = 0;

  virtual antlrcpp::Any visitVarDecl(BasicParser::VarDeclContext *context) = 0;

  virtual antlrcpp::Any visitVarDef(BasicParser::VarDefContext *context) = 0;

  virtual antlrcpp::Any visitVarParam(
      BasicParser::VarParamContext *context) = 0;

  virtual antlrcpp::Any visitArgList(BasicParser::ArgListContext *context) = 0;

  virtual antlrcpp::Any visitRecDecl(BasicParser::RecDeclContext *context) = 0;

  virtual antlrcpp::Any visitFuncSignature(
      BasicParser::FuncSignatureContext *context) = 0;

  virtual antlrcpp::Any visitFuncDef(BasicParser::FuncDefContext *context) = 0;

  virtual antlrcpp::Any visitExtFuncDecl(
      BasicParser::ExtFuncDeclContext *context) = 0;

  virtual antlrcpp::Any visitFuncParams(
      BasicParser::FuncParamsContext *context) = 0;

  virtual antlrcpp::Any visitFuncCall(
      BasicParser::FuncCallContext *context) = 0;

  virtual antlrcpp::Any visitCall(BasicParser::CallContext *context) = 0;

  virtual antlrcpp::Any visitMethod(BasicParser::MethodContext *context) = 0;

  virtual antlrcpp::Any visitIden(BasicParser::IdenContext *context) = 0;

  virtual antlrcpp::Any visitThis(BasicParser::ThisContext *context) = 0;

  virtual antlrcpp::Any visitMember(BasicParser::MemberContext *context) = 0;

  virtual antlrcpp::Any visitPExpr(BasicParser::PExprContext *context) = 0;

  virtual antlrcpp::Any visitString(BasicParser::StringContext *context) = 0;

  virtual antlrcpp::Any visitReal(BasicParser::RealContext *context) = 0;

  virtual antlrcpp::Any visitBoolT(BasicParser::BoolTContext *context) = 0;

  virtual antlrcpp::Any visitBoolF(BasicParser::BoolFContext *context) = 0;

  virtual antlrcpp::Any visitIntDec(BasicParser::IntDecContext *context) = 0;

  virtual antlrcpp::Any visitIntHex(BasicParser::IntHexContext *context) = 0;

  virtual antlrcpp::Any visitIntOct(BasicParser::IntOctContext *context) = 0;

  virtual antlrcpp::Any visitAdd(BasicParser::AddContext *context) = 0;

  virtual antlrcpp::Any visitCast(BasicParser::CastContext *context) = 0;

  virtual antlrcpp::Any visitAsg(BasicParser::AsgContext *context) = 0;

  virtual antlrcpp::Any visitMul(BasicParser::MulContext *context) = 0;

  virtual antlrcpp::Any visitLitExpr(BasicParser::LitExprContext *context) = 0;

  virtual antlrcpp::Any visitLvalExpr(
      BasicParser::LvalExprContext *context) = 0;
};

}  // namespace ch2c
