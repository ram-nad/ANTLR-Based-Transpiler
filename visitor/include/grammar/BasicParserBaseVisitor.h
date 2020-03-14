
// Generated from BasicParser.g4 by ANTLR 4.8

#pragma once

#include <antlr4-runtime/antlr4-runtime.h>
#include <grammar/BasicParserVisitor.h>

namespace ch2c {

/**
 * This class provides an empty implementation of BasicParserVisitor, which can
 * be extended to create a visitor which only needs to handle a subset of the
 * available methods.
 */
class BasicParserBaseVisitor : public BasicParserVisitor {
 public:
  virtual antlrcpp::Any visitFile(BasicParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatements(
      BasicParser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetStmt(
      BasicParser::RetStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlckStmt(
      BasicParser::BlckStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprStmt(
      BasicParser::ExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimTypes(
      BasicParser::PrimTypesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarType(
      BasicParser::VarTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeDecl(
      BasicParser::TypeDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDecl(
      BasicParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDef(BasicParser::VarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarParam(
      BasicParser::VarParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgList(
      BasicParser::ArgListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecDecl(
      BasicParser::RecDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncSignature(
      BasicParser::FuncSignatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncDef(
      BasicParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtFuncDecl(
      BasicParser::ExtFuncDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncParams(
      BasicParser::FuncParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncCall(
      BasicParser::FuncCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCall(BasicParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethod(BasicParser::MethodContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIden(BasicParser::IdenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitThis(BasicParser::ThisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMember(BasicParser::MemberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPExpr(BasicParser::PExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString(BasicParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReal(BasicParser::RealContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolT(BasicParser::BoolTContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolF(BasicParser::BoolFContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntDec(BasicParser::IntDecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntHex(BasicParser::IntHexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntOct(BasicParser::IntOctContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdd(BasicParser::AddContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCast(BasicParser::CastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAsg(BasicParser::AsgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMul(BasicParser::MulContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLitExpr(
      BasicParser::LitExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLvalExpr(
      BasicParser::LvalExprContext *ctx) override {
    return visitChildren(ctx);
  }
};

}  // namespace ch2c
