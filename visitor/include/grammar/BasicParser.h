
// Generated from BasicParser.g4 by ANTLR 4.8

#pragma once

#include <antlr4-runtime/antlr4-runtime.h>

namespace ch2c {

class BasicParser : public antlr4::Parser {
 public:
  enum {
    VAR = 1,
    RETURN = 2,
    PROC = 3,
    RECORD = 4,
    EXTERN = 5,
    THIS = 6,
    VOID = 7,
    INT = 8,
    UINT = 9,
    STRING = 10,
    REAL = 11,
    BOOL = 12,
    DOT = 13,
    COLON = 14,
    SEMICOLON = 15,
    COMMA = 16,
    OPEN_BRACES = 17,
    CLOSE_BRACES = 18,
    OPEN_PARENTHESES = 19,
    CLOSE_PARENTHESES = 20,
    ASSIGN = 21,
    ADD = 22,
    SUB = 23,
    MUL = 24,
    DIV = 25,
    MOD = 26,
    IDENTIFIER = 27,
    STRING_LITERAL = 28,
    TRUE = 29,
    FALSE = 30,
    DEC_LITERAL = 31,
    HEX_LITERAL = 32,
    OCT_LITERAL = 33,
    REAL_LITERAL = 34,
    SINGLE_LINE_COMMENT = 35,
    WHITESPACE = 36,
    MULTILINE_COMMENT_START = 37,
    MULTILINE_COMMENT_END = 38,
    COMMENT_START = 39,
    COMMENT_END = 40,
    ANYCHAR = 41
  };

  enum {
    RuleFile = 0,
    RuleStatements = 1,
    RuleRetStmt = 2,
    RuleBlckStmt = 3,
    RuleExprStmt = 4,
    RulePrimTypes = 5,
    RuleVarType = 6,
    RuleTypeDecl = 7,
    RuleVarDecl = 8,
    RuleVarDef = 9,
    RuleVarParam = 10,
    RuleArgList = 11,
    RuleRecDecl = 12,
    RuleFuncSignature = 13,
    RuleFuncDef = 14,
    RuleExtFuncDecl = 15,
    RuleFuncParams = 16,
    RuleFuncCall = 17,
    RuleLVal = 18,
    RuleLiteral = 19,
    RuleExpr = 20
  };

  BasicParser(antlr4::TokenStream *input);
  ~BasicParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN &getATN() const override { return _atn; };
  virtual const std::vector<std::string> &getTokenNames() const override {
    return _tokenNames;
  };  // deprecated: use vocabulary instead.
  virtual const std::vector<std::string> &getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary &getVocabulary() const override;

  class FileContext;
  class StatementsContext;
  class RetStmtContext;
  class BlckStmtContext;
  class ExprStmtContext;
  class PrimTypesContext;
  class VarTypeContext;
  class TypeDeclContext;
  class VarDeclContext;
  class VarDefContext;
  class VarParamContext;
  class ArgListContext;
  class RecDeclContext;
  class FuncSignatureContext;
  class FuncDefContext;
  class ExtFuncDeclContext;
  class FuncParamsContext;
  class FuncCallContext;
  class LValContext;
  class LiteralContext;
  class ExprContext;

  class FileContext : public antlr4::ParserRuleContext {
   public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VarDefContext *> varDef();
    VarDefContext *varDef(size_t i);
    std::vector<ExprStmtContext *> exprStmt();
    ExprStmtContext *exprStmt(size_t i);
    std::vector<FuncDefContext *> funcDef();
    FuncDefContext *funcDef(size_t i);
    std::vector<ExtFuncDeclContext *> extFuncDecl();
    ExtFuncDeclContext *extFuncDecl(size_t i);
    std::vector<RecDeclContext *> recDecl();
    RecDeclContext *recDecl(size_t i);

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FileContext *file();

  class StatementsContext : public antlr4::ParserRuleContext {
   public:
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprStmtContext *exprStmt();
    BlckStmtContext *blckStmt();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementsContext *statements();

  class RetStmtContext : public antlr4::ParserRuleContext {
   public:
    RetStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RetStmtContext *retStmt();

  class BlckStmtContext : public antlr4::ParserRuleContext {
   public:
    BlckStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_BRACES();
    antlr4::tree::TerminalNode *CLOSE_BRACES();
    std::vector<VarDefContext *> varDef();
    VarDefContext *varDef(size_t i);
    std::vector<ExprStmtContext *> exprStmt();
    ExprStmtContext *exprStmt(size_t i);
    std::vector<RetStmtContext *> retStmt();
    RetStmtContext *retStmt(size_t i);

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BlckStmtContext *blckStmt();

  class ExprStmtContext : public antlr4::ParserRuleContext {
   public:
    ExprStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprStmtContext *exprStmt();

  class PrimTypesContext : public antlr4::ParserRuleContext {
   public:
    PrimTypesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *UINT();
    antlr4::tree::TerminalNode *REAL();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *BOOL();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PrimTypesContext *primTypes();

  class VarTypeContext : public antlr4::ParserRuleContext {
   public:
    VarTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    PrimTypesContext *primTypes();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VarTypeContext *varType();

  class TypeDeclContext : public antlr4::ParserRuleContext {
   public:
    TypeDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    VarTypeContext *varType();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeDeclContext *typeDecl();

  class VarDeclContext : public antlr4::ParserRuleContext {
   public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode *IDENTIFIER(size_t i);
    TypeDeclContext *typeDecl();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode *COMMA(size_t i);

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VarDeclContext *varDecl();

  class VarDefContext : public antlr4::ParserRuleContext {
   public:
    VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();
    std::vector<VarDeclContext *> varDecl();
    VarDeclContext *varDecl(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *COMMA();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VarDefContext *varDef();

  class VarParamContext : public antlr4::ParserRuleContext {
   public:
    VarParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    TypeDeclContext *typeDecl();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VarParamContext *varParam();

  class ArgListContext : public antlr4::ParserRuleContext {
   public:
    ArgListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VarParamContext *> varParam();
    VarParamContext *varParam(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode *COMMA(size_t i);

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ArgListContext *argList();

  class RecDeclContext : public antlr4::ParserRuleContext {
   public:
    RecDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RECORD();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *OPEN_BRACES();
    antlr4::tree::TerminalNode *CLOSE_BRACES();
    std::vector<antlr4::tree::TerminalNode *> VAR();
    antlr4::tree::TerminalNode *VAR(size_t i);
    std::vector<VarParamContext *> varParam();
    VarParamContext *varParam(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode *SEMICOLON(size_t i);
    std::vector<FuncDefContext *> funcDef();
    FuncDefContext *funcDef(size_t i);

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RecDeclContext *recDecl();

  class FuncSignatureContext : public antlr4::ParserRuleContext {
   public:
    FuncSignatureContext(antlr4::ParserRuleContext *parent,
                         size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROC();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *OPEN_PARENTHESES();
    antlr4::tree::TerminalNode *CLOSE_PARENTHESES();
    ArgListContext *argList();
    TypeDeclContext *typeDecl();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FuncSignatureContext *funcSignature();

  class FuncDefContext : public antlr4::ParserRuleContext {
   public:
    FuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FuncSignatureContext *funcSignature();
    BlckStmtContext *blckStmt();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FuncDefContext *funcDef();

  class ExtFuncDeclContext : public antlr4::ParserRuleContext {
   public:
    ExtFuncDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXTERN();
    FuncSignatureContext *funcSignature();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExtFuncDeclContext *extFuncDecl();

  class FuncParamsContext : public antlr4::ParserRuleContext {
   public:
    FuncParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode *COMMA(size_t i);

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FuncParamsContext *funcParams();

  class FuncCallContext : public antlr4::ParserRuleContext {
   public:
    FuncCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_PARENTHESES();
    antlr4::tree::TerminalNode *CLOSE_PARENTHESES();
    FuncParamsContext *funcParams();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FuncCallContext *funcCall();

  class LValContext : public antlr4::ParserRuleContext {
   public:
    LValContext(antlr4::ParserRuleContext *parent, size_t invokingState);

    LValContext() = default;
    void copyFrom(LValContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;
  };

  class CallContext : public LValContext {
   public:
    CallContext(LValContext *ctx);

    LValContext *lVal();
    FuncCallContext *funcCall();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class MethodContext : public LValContext {
   public:
    MethodContext(LValContext *ctx);

    LValContext *lVal();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *IDENTIFIER();
    FuncCallContext *funcCall();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class IdenContext : public LValContext {
   public:
    IdenContext(LValContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class ThisContext : public LValContext {
   public:
    ThisContext(LValContext *ctx);

    antlr4::tree::TerminalNode *THIS();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class MemberContext : public LValContext {
   public:
    MemberContext(LValContext *ctx);

    LValContext *lVal();
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class PExprContext : public LValContext {
   public:
    PExprContext(LValContext *ctx);

    antlr4::tree::TerminalNode *OPEN_PARENTHESES();
    ExprContext *expr();
    antlr4::tree::TerminalNode *CLOSE_PARENTHESES();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LValContext *lVal();
  LValContext *lVal(int precedence);
  class LiteralContext : public antlr4::ParserRuleContext {
   public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);

    LiteralContext() = default;
    void copyFrom(LiteralContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;
  };

  class IntOctContext : public LiteralContext {
   public:
    IntOctContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *OCT_LITERAL();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class BoolTContext : public LiteralContext {
   public:
    BoolTContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *TRUE();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class IntDecContext : public LiteralContext {
   public:
    IntDecContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *DEC_LITERAL();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class StringContext : public LiteralContext {
   public:
    StringContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *STRING_LITERAL();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class BoolFContext : public LiteralContext {
   public:
    BoolFContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *FALSE();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class RealContext : public LiteralContext {
   public:
    RealContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *REAL_LITERAL();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class IntHexContext : public LiteralContext {
   public:
    IntHexContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *HEX_LITERAL();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LiteralContext *literal();

  class ExprContext : public antlr4::ParserRuleContext {
   public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);

    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;
  };

  class AddContext : public ExprContext {
   public:
    AddContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class CastContext : public ExprContext {
   public:
    CastContext(ExprContext *ctx);

    ExprContext *expr();
    TypeDeclContext *typeDecl();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class AsgContext : public ExprContext {
   public:
    AsgContext(ExprContext *ctx);

    LValContext *lVal();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class MulContext : public ExprContext {
   public:
    MulContext(ExprContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExprContext *> expr();
    ExprContext *expr(size_t i);
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class LitExprContext : public ExprContext {
   public:
    LitExprContext(ExprContext *ctx);

    LiteralContext *literal();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class LvalExprContext : public ExprContext {
   public:
    LvalExprContext(ExprContext *ctx);

    LValContext *lVal();

    virtual antlrcpp::Any accept(
        antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext *expr();
  ExprContext *expr(int precedence);

  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex,
                       size_t predicateIndex) override;
  bool lValSempred(LValContext *_localctx, size_t predicateIndex);
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

 private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace ch2c
