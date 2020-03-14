
// Generated from BasicParser.g4 by ANTLR 4.8

#include <grammar/BasicParserVisitor.h>

#include <grammar/BasicParser.h>

using namespace antlrcpp;
using namespace ch2c;
using namespace antlr4;

BasicParser::BasicParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA,
                                             _sharedContextCache);
}

BasicParser::~BasicParser() { delete _interpreter; }

std::string BasicParser::getGrammarFileName() const { return "BasicParser.g4"; }

const std::vector<std::string> &BasicParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary &BasicParser::getVocabulary() const { return _vocabulary; }

//----------------- FileContext
//------------------------------------------------------------------

BasicParser::FileContext::FileContext(ParserRuleContext *parent,
                                      size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<BasicParser::VarDefContext *> BasicParser::FileContext::varDef() {
  return getRuleContexts<BasicParser::VarDefContext>();
}

BasicParser::VarDefContext *BasicParser::FileContext::varDef(size_t i) {
  return getRuleContext<BasicParser::VarDefContext>(i);
}

std::vector<BasicParser::ExprStmtContext *>
BasicParser::FileContext::exprStmt() {
  return getRuleContexts<BasicParser::ExprStmtContext>();
}

BasicParser::ExprStmtContext *BasicParser::FileContext::exprStmt(size_t i) {
  return getRuleContext<BasicParser::ExprStmtContext>(i);
}

std::vector<BasicParser::FuncDefContext *> BasicParser::FileContext::funcDef() {
  return getRuleContexts<BasicParser::FuncDefContext>();
}

BasicParser::FuncDefContext *BasicParser::FileContext::funcDef(size_t i) {
  return getRuleContext<BasicParser::FuncDefContext>(i);
}

std::vector<BasicParser::ExtFuncDeclContext *>
BasicParser::FileContext::extFuncDecl() {
  return getRuleContexts<BasicParser::ExtFuncDeclContext>();
}

BasicParser::ExtFuncDeclContext *BasicParser::FileContext::extFuncDecl(
    size_t i) {
  return getRuleContext<BasicParser::ExtFuncDeclContext>(i);
}

std::vector<BasicParser::RecDeclContext *> BasicParser::FileContext::recDecl() {
  return getRuleContexts<BasicParser::RecDeclContext>();
}

BasicParser::RecDeclContext *BasicParser::FileContext::recDecl(size_t i) {
  return getRuleContext<BasicParser::RecDeclContext>(i);
}

size_t BasicParser::FileContext::getRuleIndex() const {
  return BasicParser::RuleFile;
}

antlrcpp::Any BasicParser::FileContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::FileContext *BasicParser::file() {
  FileContext *_localctx =
      _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, BasicParser::RuleFile);
  size_t _la = 0;

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (
        (((_la & ~0x3fULL) == 0) &&
         ((1ULL << _la) &
          ((1ULL << BasicParser::VAR) | (1ULL << BasicParser::PROC) |
           (1ULL << BasicParser::RECORD) | (1ULL << BasicParser::EXTERN) |
           (1ULL << BasicParser::THIS) |
           (1ULL << BasicParser::OPEN_PARENTHESES) |
           (1ULL << BasicParser::IDENTIFIER) |
           (1ULL << BasicParser::STRING_LITERAL) | (1ULL << BasicParser::TRUE) |
           (1ULL << BasicParser::FALSE) | (1ULL << BasicParser::DEC_LITERAL) |
           (1ULL << BasicParser::HEX_LITERAL) |
           (1ULL << BasicParser::OCT_LITERAL) |
           (1ULL << BasicParser::REAL_LITERAL))) != 0)) {
      setState(47);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case BasicParser::VAR: {
          setState(42);
          varDef();
          break;
        }

        case BasicParser::THIS:
        case BasicParser::OPEN_PARENTHESES:
        case BasicParser::IDENTIFIER:
        case BasicParser::STRING_LITERAL:
        case BasicParser::TRUE:
        case BasicParser::FALSE:
        case BasicParser::DEC_LITERAL:
        case BasicParser::HEX_LITERAL:
        case BasicParser::OCT_LITERAL:
        case BasicParser::REAL_LITERAL: {
          setState(43);
          exprStmt();
          break;
        }

        case BasicParser::PROC: {
          setState(44);
          funcDef();
          break;
        }

        case BasicParser::EXTERN: {
          setState(45);
          extFuncDecl();
          break;
        }

        case BasicParser::RECORD: {
          setState(46);
          recDecl();
          break;
        }

        default:
          throw NoViableAltException(this);
      }
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext
//------------------------------------------------------------------

BasicParser::StatementsContext::StatementsContext(ParserRuleContext *parent,
                                                  size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

BasicParser::ExprStmtContext *BasicParser::StatementsContext::exprStmt() {
  return getRuleContext<BasicParser::ExprStmtContext>(0);
}

BasicParser::BlckStmtContext *BasicParser::StatementsContext::blckStmt() {
  return getRuleContext<BasicParser::BlckStmtContext>(0);
}

size_t BasicParser::StatementsContext::getRuleIndex() const {
  return BasicParser::RuleStatements;
}

antlrcpp::Any BasicParser::StatementsContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::StatementsContext *BasicParser::statements() {
  StatementsContext *_localctx =
      _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 2, BasicParser::RuleStatements);

  auto onExit = finally([=] { exitRule(); });
  try {
    setState(54);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BasicParser::THIS:
      case BasicParser::OPEN_PARENTHESES:
      case BasicParser::IDENTIFIER:
      case BasicParser::STRING_LITERAL:
      case BasicParser::TRUE:
      case BasicParser::FALSE:
      case BasicParser::DEC_LITERAL:
      case BasicParser::HEX_LITERAL:
      case BasicParser::OCT_LITERAL:
      case BasicParser::REAL_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(52);
        exprStmt();
        break;
      }

      case BasicParser::OPEN_BRACES: {
        enterOuterAlt(_localctx, 2);
        setState(53);
        blckStmt();
        break;
      }

      default:
        throw NoViableAltException(this);
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetStmtContext
//------------------------------------------------------------------

BasicParser::RetStmtContext::RetStmtContext(ParserRuleContext *parent,
                                            size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *BasicParser::RetStmtContext::RETURN() {
  return getToken(BasicParser::RETURN, 0);
}

BasicParser::ExprContext *BasicParser::RetStmtContext::expr() {
  return getRuleContext<BasicParser::ExprContext>(0);
}

tree::TerminalNode *BasicParser::RetStmtContext::SEMICOLON() {
  return getToken(BasicParser::SEMICOLON, 0);
}

size_t BasicParser::RetStmtContext::getRuleIndex() const {
  return BasicParser::RuleRetStmt;
}

antlrcpp::Any BasicParser::RetStmtContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitRetStmt(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::RetStmtContext *BasicParser::retStmt() {
  RetStmtContext *_localctx =
      _tracker.createInstance<RetStmtContext>(_ctx, getState());
  enterRule(_localctx, 4, BasicParser::RuleRetStmt);

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(BasicParser::RETURN);
    setState(57);
    expr(0);
    setState(58);
    match(BasicParser::SEMICOLON);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlckStmtContext
//------------------------------------------------------------------

BasicParser::BlckStmtContext::BlckStmtContext(ParserRuleContext *parent,
                                              size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *BasicParser::BlckStmtContext::OPEN_BRACES() {
  return getToken(BasicParser::OPEN_BRACES, 0);
}

tree::TerminalNode *BasicParser::BlckStmtContext::CLOSE_BRACES() {
  return getToken(BasicParser::CLOSE_BRACES, 0);
}

std::vector<BasicParser::VarDefContext *>
BasicParser::BlckStmtContext::varDef() {
  return getRuleContexts<BasicParser::VarDefContext>();
}

BasicParser::VarDefContext *BasicParser::BlckStmtContext::varDef(size_t i) {
  return getRuleContext<BasicParser::VarDefContext>(i);
}

std::vector<BasicParser::ExprStmtContext *>
BasicParser::BlckStmtContext::exprStmt() {
  return getRuleContexts<BasicParser::ExprStmtContext>();
}

BasicParser::ExprStmtContext *BasicParser::BlckStmtContext::exprStmt(size_t i) {
  return getRuleContext<BasicParser::ExprStmtContext>(i);
}

std::vector<BasicParser::RetStmtContext *>
BasicParser::BlckStmtContext::retStmt() {
  return getRuleContexts<BasicParser::RetStmtContext>();
}

BasicParser::RetStmtContext *BasicParser::BlckStmtContext::retStmt(size_t i) {
  return getRuleContext<BasicParser::RetStmtContext>(i);
}

size_t BasicParser::BlckStmtContext::getRuleIndex() const {
  return BasicParser::RuleBlckStmt;
}

antlrcpp::Any BasicParser::BlckStmtContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitBlckStmt(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::BlckStmtContext *BasicParser::blckStmt() {
  BlckStmtContext *_localctx =
      _tracker.createInstance<BlckStmtContext>(_ctx, getState());
  enterRule(_localctx, 6, BasicParser::RuleBlckStmt);
  size_t _la = 0;

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    match(BasicParser::OPEN_BRACES);
    setState(66);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (
        (((_la & ~0x3fULL) == 0) &&
         ((1ULL << _la) &
          ((1ULL << BasicParser::VAR) | (1ULL << BasicParser::RETURN) |
           (1ULL << BasicParser::THIS) |
           (1ULL << BasicParser::OPEN_PARENTHESES) |
           (1ULL << BasicParser::IDENTIFIER) |
           (1ULL << BasicParser::STRING_LITERAL) | (1ULL << BasicParser::TRUE) |
           (1ULL << BasicParser::FALSE) | (1ULL << BasicParser::DEC_LITERAL) |
           (1ULL << BasicParser::HEX_LITERAL) |
           (1ULL << BasicParser::OCT_LITERAL) |
           (1ULL << BasicParser::REAL_LITERAL))) != 0)) {
      setState(64);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case BasicParser::VAR: {
          setState(61);
          varDef();
          break;
        }

        case BasicParser::THIS:
        case BasicParser::OPEN_PARENTHESES:
        case BasicParser::IDENTIFIER:
        case BasicParser::STRING_LITERAL:
        case BasicParser::TRUE:
        case BasicParser::FALSE:
        case BasicParser::DEC_LITERAL:
        case BasicParser::HEX_LITERAL:
        case BasicParser::OCT_LITERAL:
        case BasicParser::REAL_LITERAL: {
          setState(62);
          exprStmt();
          break;
        }

        case BasicParser::RETURN: {
          setState(63);
          retStmt();
          break;
        }

        default:
          throw NoViableAltException(this);
      }
      setState(68);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(69);
    match(BasicParser::CLOSE_BRACES);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprStmtContext
//------------------------------------------------------------------

BasicParser::ExprStmtContext::ExprStmtContext(ParserRuleContext *parent,
                                              size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

BasicParser::ExprContext *BasicParser::ExprStmtContext::expr() {
  return getRuleContext<BasicParser::ExprContext>(0);
}

tree::TerminalNode *BasicParser::ExprStmtContext::SEMICOLON() {
  return getToken(BasicParser::SEMICOLON, 0);
}

size_t BasicParser::ExprStmtContext::getRuleIndex() const {
  return BasicParser::RuleExprStmt;
}

antlrcpp::Any BasicParser::ExprStmtContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitExprStmt(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::ExprStmtContext *BasicParser::exprStmt() {
  ExprStmtContext *_localctx =
      _tracker.createInstance<ExprStmtContext>(_ctx, getState());
  enterRule(_localctx, 8, BasicParser::RuleExprStmt);

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    expr(0);
    setState(72);
    match(BasicParser::SEMICOLON);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimTypesContext
//------------------------------------------------------------------

BasicParser::PrimTypesContext::PrimTypesContext(ParserRuleContext *parent,
                                                size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *BasicParser::PrimTypesContext::INT() {
  return getToken(BasicParser::INT, 0);
}

tree::TerminalNode *BasicParser::PrimTypesContext::UINT() {
  return getToken(BasicParser::UINT, 0);
}

tree::TerminalNode *BasicParser::PrimTypesContext::REAL() {
  return getToken(BasicParser::REAL, 0);
}

tree::TerminalNode *BasicParser::PrimTypesContext::STRING() {
  return getToken(BasicParser::STRING, 0);
}

tree::TerminalNode *BasicParser::PrimTypesContext::BOOL() {
  return getToken(BasicParser::BOOL, 0);
}

size_t BasicParser::PrimTypesContext::getRuleIndex() const {
  return BasicParser::RulePrimTypes;
}

antlrcpp::Any BasicParser::PrimTypesContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitPrimTypes(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::PrimTypesContext *BasicParser::primTypes() {
  PrimTypesContext *_localctx =
      _tracker.createInstance<PrimTypesContext>(_ctx, getState());
  enterRule(_localctx, 10, BasicParser::RulePrimTypes);
  size_t _la = 0;

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    _la = _input->LA(1);
    if (!((((_la & ~0x3fULL) == 0) &&
           ((1ULL << _la) &
            ((1ULL << BasicParser::INT) | (1ULL << BasicParser::UINT) |
             (1ULL << BasicParser::STRING) | (1ULL << BasicParser::REAL) |
             (1ULL << BasicParser::BOOL))) != 0))) {
      _errHandler->recoverInline(this);
    } else {
      _errHandler->reportMatch(this);
      consume();
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarTypeContext
//------------------------------------------------------------------

BasicParser::VarTypeContext::VarTypeContext(ParserRuleContext *parent,
                                            size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *BasicParser::VarTypeContext::IDENTIFIER() {
  return getToken(BasicParser::IDENTIFIER, 0);
}

BasicParser::PrimTypesContext *BasicParser::VarTypeContext::primTypes() {
  return getRuleContext<BasicParser::PrimTypesContext>(0);
}

size_t BasicParser::VarTypeContext::getRuleIndex() const {
  return BasicParser::RuleVarType;
}

antlrcpp::Any BasicParser::VarTypeContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitVarType(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::VarTypeContext *BasicParser::varType() {
  VarTypeContext *_localctx =
      _tracker.createInstance<VarTypeContext>(_ctx, getState());
  enterRule(_localctx, 12, BasicParser::RuleVarType);

  auto onExit = finally([=] { exitRule(); });
  try {
    setState(78);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BasicParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(76);
        match(BasicParser::IDENTIFIER);
        break;
      }

      case BasicParser::INT:
      case BasicParser::UINT:
      case BasicParser::STRING:
      case BasicParser::REAL:
      case BasicParser::BOOL: {
        enterOuterAlt(_localctx, 2);
        setState(77);
        primTypes();
        break;
      }

      default:
        throw NoViableAltException(this);
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclContext
//------------------------------------------------------------------

BasicParser::TypeDeclContext::TypeDeclContext(ParserRuleContext *parent,
                                              size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *BasicParser::TypeDeclContext::COLON() {
  return getToken(BasicParser::COLON, 0);
}

BasicParser::VarTypeContext *BasicParser::TypeDeclContext::varType() {
  return getRuleContext<BasicParser::VarTypeContext>(0);
}

size_t BasicParser::TypeDeclContext::getRuleIndex() const {
  return BasicParser::RuleTypeDecl;
}

antlrcpp::Any BasicParser::TypeDeclContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitTypeDecl(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::TypeDeclContext *BasicParser::typeDecl() {
  TypeDeclContext *_localctx =
      _tracker.createInstance<TypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 14, BasicParser::RuleTypeDecl);

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    match(BasicParser::COLON);
    setState(81);
    varType();

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext
//------------------------------------------------------------------

BasicParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent,
                                            size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<tree::TerminalNode *> BasicParser::VarDeclContext::IDENTIFIER() {
  return getTokens(BasicParser::IDENTIFIER);
}

tree::TerminalNode *BasicParser::VarDeclContext::IDENTIFIER(size_t i) {
  return getToken(BasicParser::IDENTIFIER, i);
}

BasicParser::TypeDeclContext *BasicParser::VarDeclContext::typeDecl() {
  return getRuleContext<BasicParser::TypeDeclContext>(0);
}

tree::TerminalNode *BasicParser::VarDeclContext::ASSIGN() {
  return getToken(BasicParser::ASSIGN, 0);
}

BasicParser::ExprContext *BasicParser::VarDeclContext::expr() {
  return getRuleContext<BasicParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> BasicParser::VarDeclContext::COMMA() {
  return getTokens(BasicParser::COMMA);
}

tree::TerminalNode *BasicParser::VarDeclContext::COMMA(size_t i) {
  return getToken(BasicParser::COMMA, i);
}

size_t BasicParser::VarDeclContext::getRuleIndex() const {
  return BasicParser::RuleVarDecl;
}

antlrcpp::Any BasicParser::VarDeclContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::VarDeclContext *BasicParser::varDecl() {
  VarDeclContext *_localctx =
      _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 16, BasicParser::RuleVarDecl);
  size_t _la = 0;

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(BasicParser::IDENTIFIER);
    setState(88);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BasicParser::COMMA) {
      setState(84);
      match(BasicParser::COMMA);
      setState(85);
      match(BasicParser::IDENTIFIER);
      setState(90);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(97);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
        _input, 8, _ctx)) {
      case 1: {
        setState(91);
        typeDecl();
        break;
      }

      case 2: {
        setState(93);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == BasicParser::COLON) {
          setState(92);
          typeDecl();
        }
        setState(95);
        match(BasicParser::ASSIGN);
        setState(96);
        expr(0);
        break;
      }
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext
//------------------------------------------------------------------

BasicParser::VarDefContext::VarDefContext(ParserRuleContext *parent,
                                          size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *BasicParser::VarDefContext::VAR() {
  return getToken(BasicParser::VAR, 0);
}

std::vector<BasicParser::VarDeclContext *>
BasicParser::VarDefContext::varDecl() {
  return getRuleContexts<BasicParser::VarDeclContext>();
}

BasicParser::VarDeclContext *BasicParser::VarDefContext::varDecl(size_t i) {
  return getRuleContext<BasicParser::VarDeclContext>(i);
}

tree::TerminalNode *BasicParser::VarDefContext::SEMICOLON() {
  return getToken(BasicParser::SEMICOLON, 0);
}

tree::TerminalNode *BasicParser::VarDefContext::COMMA() {
  return getToken(BasicParser::COMMA, 0);
}

size_t BasicParser::VarDefContext::getRuleIndex() const {
  return BasicParser::RuleVarDef;
}

antlrcpp::Any BasicParser::VarDefContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitVarDef(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::VarDefContext *BasicParser::varDef() {
  VarDefContext *_localctx =
      _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 18, BasicParser::RuleVarDef);
  size_t _la = 0;

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    match(BasicParser::VAR);
    setState(100);
    varDecl();
    setState(103);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BasicParser::COMMA) {
      setState(101);
      match(BasicParser::COMMA);
      setState(102);
      varDecl();
    }
    setState(105);
    match(BasicParser::SEMICOLON);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarParamContext
//------------------------------------------------------------------

BasicParser::VarParamContext::VarParamContext(ParserRuleContext *parent,
                                              size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *BasicParser::VarParamContext::IDENTIFIER() {
  return getToken(BasicParser::IDENTIFIER, 0);
}

BasicParser::TypeDeclContext *BasicParser::VarParamContext::typeDecl() {
  return getRuleContext<BasicParser::TypeDeclContext>(0);
}

size_t BasicParser::VarParamContext::getRuleIndex() const {
  return BasicParser::RuleVarParam;
}

antlrcpp::Any BasicParser::VarParamContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitVarParam(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::VarParamContext *BasicParser::varParam() {
  VarParamContext *_localctx =
      _tracker.createInstance<VarParamContext>(_ctx, getState());
  enterRule(_localctx, 20, BasicParser::RuleVarParam);

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    match(BasicParser::IDENTIFIER);
    setState(108);
    typeDecl();

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgListContext
//------------------------------------------------------------------

BasicParser::ArgListContext::ArgListContext(ParserRuleContext *parent,
                                            size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<BasicParser::VarParamContext *>
BasicParser::ArgListContext::varParam() {
  return getRuleContexts<BasicParser::VarParamContext>();
}

BasicParser::VarParamContext *BasicParser::ArgListContext::varParam(size_t i) {
  return getRuleContext<BasicParser::VarParamContext>(i);
}

std::vector<tree::TerminalNode *> BasicParser::ArgListContext::COMMA() {
  return getTokens(BasicParser::COMMA);
}

tree::TerminalNode *BasicParser::ArgListContext::COMMA(size_t i) {
  return getToken(BasicParser::COMMA, i);
}

size_t BasicParser::ArgListContext::getRuleIndex() const {
  return BasicParser::RuleArgList;
}

antlrcpp::Any BasicParser::ArgListContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitArgList(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::ArgListContext *BasicParser::argList() {
  ArgListContext *_localctx =
      _tracker.createInstance<ArgListContext>(_ctx, getState());
  enterRule(_localctx, 22, BasicParser::RuleArgList);
  size_t _la = 0;

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    varParam();
    setState(115);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BasicParser::COMMA) {
      setState(111);
      match(BasicParser::COMMA);
      setState(112);
      varParam();
      setState(117);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RecDeclContext
//------------------------------------------------------------------

BasicParser::RecDeclContext::RecDeclContext(ParserRuleContext *parent,
                                            size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *BasicParser::RecDeclContext::RECORD() {
  return getToken(BasicParser::RECORD, 0);
}

tree::TerminalNode *BasicParser::RecDeclContext::IDENTIFIER() {
  return getToken(BasicParser::IDENTIFIER, 0);
}

tree::TerminalNode *BasicParser::RecDeclContext::OPEN_BRACES() {
  return getToken(BasicParser::OPEN_BRACES, 0);
}

tree::TerminalNode *BasicParser::RecDeclContext::CLOSE_BRACES() {
  return getToken(BasicParser::CLOSE_BRACES, 0);
}

std::vector<tree::TerminalNode *> BasicParser::RecDeclContext::VAR() {
  return getTokens(BasicParser::VAR);
}

tree::TerminalNode *BasicParser::RecDeclContext::VAR(size_t i) {
  return getToken(BasicParser::VAR, i);
}

std::vector<BasicParser::VarParamContext *>
BasicParser::RecDeclContext::varParam() {
  return getRuleContexts<BasicParser::VarParamContext>();
}

BasicParser::VarParamContext *BasicParser::RecDeclContext::varParam(size_t i) {
  return getRuleContext<BasicParser::VarParamContext>(i);
}

std::vector<tree::TerminalNode *> BasicParser::RecDeclContext::SEMICOLON() {
  return getTokens(BasicParser::SEMICOLON);
}

tree::TerminalNode *BasicParser::RecDeclContext::SEMICOLON(size_t i) {
  return getToken(BasicParser::SEMICOLON, i);
}

std::vector<BasicParser::FuncDefContext *>
BasicParser::RecDeclContext::funcDef() {
  return getRuleContexts<BasicParser::FuncDefContext>();
}

BasicParser::FuncDefContext *BasicParser::RecDeclContext::funcDef(size_t i) {
  return getRuleContext<BasicParser::FuncDefContext>(i);
}

size_t BasicParser::RecDeclContext::getRuleIndex() const {
  return BasicParser::RuleRecDecl;
}

antlrcpp::Any BasicParser::RecDeclContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitRecDecl(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::RecDeclContext *BasicParser::recDecl() {
  RecDeclContext *_localctx =
      _tracker.createInstance<RecDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, BasicParser::RuleRecDecl);
  size_t _la = 0;

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(BasicParser::RECORD);
    setState(119);
    match(BasicParser::IDENTIFIER);
    setState(120);
    match(BasicParser::OPEN_BRACES);
    setState(128);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BasicParser::VAR

           || _la == BasicParser::PROC) {
      setState(126);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case BasicParser::VAR: {
          setState(121);
          match(BasicParser::VAR);
          setState(122);
          varParam();
          setState(123);
          match(BasicParser::SEMICOLON);
          break;
        }

        case BasicParser::PROC: {
          setState(125);
          funcDef();
          break;
        }

        default:
          throw NoViableAltException(this);
      }
      setState(130);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(131);
    match(BasicParser::CLOSE_BRACES);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncSignatureContext
//------------------------------------------------------------------

BasicParser::FuncSignatureContext::FuncSignatureContext(
    ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *BasicParser::FuncSignatureContext::PROC() {
  return getToken(BasicParser::PROC, 0);
}

tree::TerminalNode *BasicParser::FuncSignatureContext::IDENTIFIER() {
  return getToken(BasicParser::IDENTIFIER, 0);
}

tree::TerminalNode *BasicParser::FuncSignatureContext::OPEN_PARENTHESES() {
  return getToken(BasicParser::OPEN_PARENTHESES, 0);
}

tree::TerminalNode *BasicParser::FuncSignatureContext::CLOSE_PARENTHESES() {
  return getToken(BasicParser::CLOSE_PARENTHESES, 0);
}

BasicParser::ArgListContext *BasicParser::FuncSignatureContext::argList() {
  return getRuleContext<BasicParser::ArgListContext>(0);
}

BasicParser::TypeDeclContext *BasicParser::FuncSignatureContext::typeDecl() {
  return getRuleContext<BasicParser::TypeDeclContext>(0);
}

size_t BasicParser::FuncSignatureContext::getRuleIndex() const {
  return BasicParser::RuleFuncSignature;
}

antlrcpp::Any BasicParser::FuncSignatureContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitFuncSignature(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::FuncSignatureContext *BasicParser::funcSignature() {
  FuncSignatureContext *_localctx =
      _tracker.createInstance<FuncSignatureContext>(_ctx, getState());
  enterRule(_localctx, 26, BasicParser::RuleFuncSignature);
  size_t _la = 0;

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    match(BasicParser::PROC);
    setState(134);
    match(BasicParser::IDENTIFIER);
    setState(135);
    match(BasicParser::OPEN_PARENTHESES);
    setState(137);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BasicParser::IDENTIFIER) {
      setState(136);
      argList();
    }
    setState(139);
    match(BasicParser::CLOSE_PARENTHESES);
    setState(141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BasicParser::COLON) {
      setState(140);
      typeDecl();
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext
//------------------------------------------------------------------

BasicParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent,
                                            size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

BasicParser::FuncSignatureContext *
BasicParser::FuncDefContext::funcSignature() {
  return getRuleContext<BasicParser::FuncSignatureContext>(0);
}

BasicParser::BlckStmtContext *BasicParser::FuncDefContext::blckStmt() {
  return getRuleContext<BasicParser::BlckStmtContext>(0);
}

size_t BasicParser::FuncDefContext::getRuleIndex() const {
  return BasicParser::RuleFuncDef;
}

antlrcpp::Any BasicParser::FuncDefContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::FuncDefContext *BasicParser::funcDef() {
  FuncDefContext *_localctx =
      _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 28, BasicParser::RuleFuncDef);

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    funcSignature();
    setState(144);
    blckStmt();

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExtFuncDeclContext
//------------------------------------------------------------------

BasicParser::ExtFuncDeclContext::ExtFuncDeclContext(ParserRuleContext *parent,
                                                    size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *BasicParser::ExtFuncDeclContext::EXTERN() {
  return getToken(BasicParser::EXTERN, 0);
}

BasicParser::FuncSignatureContext *
BasicParser::ExtFuncDeclContext::funcSignature() {
  return getRuleContext<BasicParser::FuncSignatureContext>(0);
}

tree::TerminalNode *BasicParser::ExtFuncDeclContext::SEMICOLON() {
  return getToken(BasicParser::SEMICOLON, 0);
}

tree::TerminalNode *BasicParser::ExtFuncDeclContext::IDENTIFIER() {
  return getToken(BasicParser::IDENTIFIER, 0);
}

size_t BasicParser::ExtFuncDeclContext::getRuleIndex() const {
  return BasicParser::RuleExtFuncDecl;
}

antlrcpp::Any BasicParser::ExtFuncDeclContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitExtFuncDecl(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::ExtFuncDeclContext *BasicParser::extFuncDecl() {
  ExtFuncDeclContext *_localctx =
      _tracker.createInstance<ExtFuncDeclContext>(_ctx, getState());
  enterRule(_localctx, 30, BasicParser::RuleExtFuncDecl);
  size_t _la = 0;

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    match(BasicParser::EXTERN);
    setState(148);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BasicParser::IDENTIFIER) {
      setState(147);
      match(BasicParser::IDENTIFIER);
    }
    setState(150);
    funcSignature();
    setState(151);
    match(BasicParser::SEMICOLON);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncParamsContext
//------------------------------------------------------------------

BasicParser::FuncParamsContext::FuncParamsContext(ParserRuleContext *parent,
                                                  size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

std::vector<BasicParser::ExprContext *> BasicParser::FuncParamsContext::expr() {
  return getRuleContexts<BasicParser::ExprContext>();
}

BasicParser::ExprContext *BasicParser::FuncParamsContext::expr(size_t i) {
  return getRuleContext<BasicParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> BasicParser::FuncParamsContext::COMMA() {
  return getTokens(BasicParser::COMMA);
}

tree::TerminalNode *BasicParser::FuncParamsContext::COMMA(size_t i) {
  return getToken(BasicParser::COMMA, i);
}

size_t BasicParser::FuncParamsContext::getRuleIndex() const {
  return BasicParser::RuleFuncParams;
}

antlrcpp::Any BasicParser::FuncParamsContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitFuncParams(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::FuncParamsContext *BasicParser::funcParams() {
  FuncParamsContext *_localctx =
      _tracker.createInstance<FuncParamsContext>(_ctx, getState());
  enterRule(_localctx, 32, BasicParser::RuleFuncParams);
  size_t _la = 0;

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    expr(0);
    setState(158);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BasicParser::COMMA) {
      setState(154);
      match(BasicParser::COMMA);
      setState(155);
      expr(0);
      setState(160);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncCallContext
//------------------------------------------------------------------

BasicParser::FuncCallContext::FuncCallContext(ParserRuleContext *parent,
                                              size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

tree::TerminalNode *BasicParser::FuncCallContext::OPEN_PARENTHESES() {
  return getToken(BasicParser::OPEN_PARENTHESES, 0);
}

tree::TerminalNode *BasicParser::FuncCallContext::CLOSE_PARENTHESES() {
  return getToken(BasicParser::CLOSE_PARENTHESES, 0);
}

BasicParser::FuncParamsContext *BasicParser::FuncCallContext::funcParams() {
  return getRuleContext<BasicParser::FuncParamsContext>(0);
}

size_t BasicParser::FuncCallContext::getRuleIndex() const {
  return BasicParser::RuleFuncCall;
}

antlrcpp::Any BasicParser::FuncCallContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitFuncCall(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::FuncCallContext *BasicParser::funcCall() {
  FuncCallContext *_localctx =
      _tracker.createInstance<FuncCallContext>(_ctx, getState());
  enterRule(_localctx, 34, BasicParser::RuleFuncCall);
  size_t _la = 0;

  auto onExit = finally([=] { exitRule(); });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    match(BasicParser::OPEN_PARENTHESES);
    setState(163);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~0x3fULL) == 0) &&
         ((1ULL << _la) &
          ((1ULL << BasicParser::THIS) |
           (1ULL << BasicParser::OPEN_PARENTHESES) |
           (1ULL << BasicParser::IDENTIFIER) |
           (1ULL << BasicParser::STRING_LITERAL) | (1ULL << BasicParser::TRUE) |
           (1ULL << BasicParser::FALSE) | (1ULL << BasicParser::DEC_LITERAL) |
           (1ULL << BasicParser::HEX_LITERAL) |
           (1ULL << BasicParser::OCT_LITERAL) |
           (1ULL << BasicParser::REAL_LITERAL))) != 0)) {
      setState(162);
      funcParams();
    }
    setState(165);
    match(BasicParser::CLOSE_PARENTHESES);

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext
//------------------------------------------------------------------

BasicParser::LValContext::LValContext(ParserRuleContext *parent,
                                      size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

size_t BasicParser::LValContext::getRuleIndex() const {
  return BasicParser::RuleLVal;
}

void BasicParser::LValContext::copyFrom(LValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CallContext
//------------------------------------------------------------------

BasicParser::LValContext *BasicParser::CallContext::lVal() {
  return getRuleContext<BasicParser::LValContext>(0);
}

BasicParser::FuncCallContext *BasicParser::CallContext::funcCall() {
  return getRuleContext<BasicParser::FuncCallContext>(0);
}

BasicParser::CallContext::CallContext(LValContext *ctx) { copyFrom(ctx); }

antlrcpp::Any BasicParser::CallContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MethodContext
//------------------------------------------------------------------

BasicParser::LValContext *BasicParser::MethodContext::lVal() {
  return getRuleContext<BasicParser::LValContext>(0);
}

tree::TerminalNode *BasicParser::MethodContext::DOT() {
  return getToken(BasicParser::DOT, 0);
}

tree::TerminalNode *BasicParser::MethodContext::IDENTIFIER() {
  return getToken(BasicParser::IDENTIFIER, 0);
}

BasicParser::FuncCallContext *BasicParser::MethodContext::funcCall() {
  return getRuleContext<BasicParser::FuncCallContext>(0);
}

BasicParser::MethodContext::MethodContext(LValContext *ctx) { copyFrom(ctx); }

antlrcpp::Any BasicParser::MethodContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitMethod(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdenContext
//------------------------------------------------------------------

tree::TerminalNode *BasicParser::IdenContext::IDENTIFIER() {
  return getToken(BasicParser::IDENTIFIER, 0);
}

BasicParser::IdenContext::IdenContext(LValContext *ctx) { copyFrom(ctx); }

antlrcpp::Any BasicParser::IdenContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitIden(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ThisContext
//------------------------------------------------------------------

tree::TerminalNode *BasicParser::ThisContext::THIS() {
  return getToken(BasicParser::THIS, 0);
}

BasicParser::ThisContext::ThisContext(LValContext *ctx) { copyFrom(ctx); }

antlrcpp::Any BasicParser::ThisContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitThis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberContext
//------------------------------------------------------------------

BasicParser::LValContext *BasicParser::MemberContext::lVal() {
  return getRuleContext<BasicParser::LValContext>(0);
}

tree::TerminalNode *BasicParser::MemberContext::DOT() {
  return getToken(BasicParser::DOT, 0);
}

tree::TerminalNode *BasicParser::MemberContext::IDENTIFIER() {
  return getToken(BasicParser::IDENTIFIER, 0);
}

BasicParser::MemberContext::MemberContext(LValContext *ctx) { copyFrom(ctx); }

antlrcpp::Any BasicParser::MemberContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitMember(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PExprContext
//------------------------------------------------------------------

tree::TerminalNode *BasicParser::PExprContext::OPEN_PARENTHESES() {
  return getToken(BasicParser::OPEN_PARENTHESES, 0);
}

BasicParser::ExprContext *BasicParser::PExprContext::expr() {
  return getRuleContext<BasicParser::ExprContext>(0);
}

tree::TerminalNode *BasicParser::PExprContext::CLOSE_PARENTHESES() {
  return getToken(BasicParser::CLOSE_PARENTHESES, 0);
}

BasicParser::PExprContext::PExprContext(LValContext *ctx) { copyFrom(ctx); }

antlrcpp::Any BasicParser::PExprContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitPExpr(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::LValContext *BasicParser::lVal() { return lVal(0); }

BasicParser::LValContext *BasicParser::lVal(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  BasicParser::LValContext *_localctx =
      _tracker.createInstance<LValContext>(_ctx, parentState);
  BasicParser::LValContext *previousContext = _localctx;
  (void)previousContext;  // Silence compiler, in case the context is not used
                          // by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, BasicParser::RuleLVal, precedence);

  auto onExit = finally([=] { unrollRecursionContexts(parentContext); });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(174);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BasicParser::THIS: {
        _localctx = _tracker.createInstance<ThisContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(168);
        match(BasicParser::THIS);
        break;
      }

      case BasicParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<IdenContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(169);
        match(BasicParser::IDENTIFIER);
        break;
      }

      case BasicParser::OPEN_PARENTHESES: {
        _localctx = _tracker.createInstance<PExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(170);
        match(BasicParser::OPEN_PARENTHESES);
        setState(171);
        expr(0);
        setState(172);
        match(BasicParser::CLOSE_PARENTHESES);
        break;
      }

      default:
        throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(187);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20,
                                                                     _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty()) triggerExitRuleEvent();
        previousContext = _localctx;
        setState(185);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
            _input, 19, _ctx)) {
          case 1: {
            auto newContext = _tracker.createInstance<MethodContext>(
                _tracker.createInstance<LValContext>(parentContext,
                                                     parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleLVal);
            setState(176);

            if (!(precpred(_ctx, 4)))
              throw FailedPredicateException(this, "precpred(_ctx, 4)");
            setState(177);
            match(BasicParser::DOT);
            setState(178);
            match(BasicParser::IDENTIFIER);
            setState(179);
            funcCall();
            break;
          }

          case 2: {
            auto newContext = _tracker.createInstance<MemberContext>(
                _tracker.createInstance<LValContext>(parentContext,
                                                     parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleLVal);
            setState(180);

            if (!(precpred(_ctx, 3)))
              throw FailedPredicateException(this, "precpred(_ctx, 3)");
            setState(181);
            match(BasicParser::DOT);
            setState(182);
            match(BasicParser::IDENTIFIER);
            break;
          }

          case 3: {
            auto newContext = _tracker.createInstance<CallContext>(
                _tracker.createInstance<LValContext>(parentContext,
                                                     parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleLVal);
            setState(183);

            if (!(precpred(_ctx, 2)))
              throw FailedPredicateException(this, "precpred(_ctx, 2)");
            setState(184);
            funcCall();
            break;
          }
        }
      }
      setState(189);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
          _input, 20, _ctx);
    }
  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LiteralContext
//------------------------------------------------------------------

BasicParser::LiteralContext::LiteralContext(ParserRuleContext *parent,
                                            size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

size_t BasicParser::LiteralContext::getRuleIndex() const {
  return BasicParser::RuleLiteral;
}

void BasicParser::LiteralContext::copyFrom(LiteralContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IntOctContext
//------------------------------------------------------------------

tree::TerminalNode *BasicParser::IntOctContext::OCT_LITERAL() {
  return getToken(BasicParser::OCT_LITERAL, 0);
}

BasicParser::IntOctContext::IntOctContext(LiteralContext *ctx) {
  copyFrom(ctx);
}

antlrcpp::Any BasicParser::IntOctContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitIntOct(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolTContext
//------------------------------------------------------------------

tree::TerminalNode *BasicParser::BoolTContext::TRUE() {
  return getToken(BasicParser::TRUE, 0);
}

BasicParser::BoolTContext::BoolTContext(LiteralContext *ctx) { copyFrom(ctx); }

antlrcpp::Any BasicParser::BoolTContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitBoolT(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntDecContext
//------------------------------------------------------------------

tree::TerminalNode *BasicParser::IntDecContext::DEC_LITERAL() {
  return getToken(BasicParser::DEC_LITERAL, 0);
}

BasicParser::IntDecContext::IntDecContext(LiteralContext *ctx) {
  copyFrom(ctx);
}

antlrcpp::Any BasicParser::IntDecContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitIntDec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringContext
//------------------------------------------------------------------

tree::TerminalNode *BasicParser::StringContext::STRING_LITERAL() {
  return getToken(BasicParser::STRING_LITERAL, 0);
}

BasicParser::StringContext::StringContext(LiteralContext *ctx) {
  copyFrom(ctx);
}

antlrcpp::Any BasicParser::StringContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolFContext
//------------------------------------------------------------------

tree::TerminalNode *BasicParser::BoolFContext::FALSE() {
  return getToken(BasicParser::FALSE, 0);
}

BasicParser::BoolFContext::BoolFContext(LiteralContext *ctx) { copyFrom(ctx); }

antlrcpp::Any BasicParser::BoolFContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitBoolF(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RealContext
//------------------------------------------------------------------

tree::TerminalNode *BasicParser::RealContext::REAL_LITERAL() {
  return getToken(BasicParser::REAL_LITERAL, 0);
}

BasicParser::RealContext::RealContext(LiteralContext *ctx) { copyFrom(ctx); }

antlrcpp::Any BasicParser::RealContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitReal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntHexContext
//------------------------------------------------------------------

tree::TerminalNode *BasicParser::IntHexContext::HEX_LITERAL() {
  return getToken(BasicParser::HEX_LITERAL, 0);
}

BasicParser::IntHexContext::IntHexContext(LiteralContext *ctx) {
  copyFrom(ctx);
}

antlrcpp::Any BasicParser::IntHexContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitIntHex(this);
  else
    return visitor->visitChildren(this);
}
BasicParser::LiteralContext *BasicParser::literal() {
  LiteralContext *_localctx =
      _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 38, BasicParser::RuleLiteral);

  auto onExit = finally([=] { exitRule(); });
  try {
    setState(197);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BasicParser::STRING_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(
            _tracker.createInstance<BasicParser::StringContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(190);
        match(BasicParser::STRING_LITERAL);
        break;
      }

      case BasicParser::REAL_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(
            _tracker.createInstance<BasicParser::RealContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(191);
        match(BasicParser::REAL_LITERAL);
        break;
      }

      case BasicParser::TRUE: {
        _localctx = dynamic_cast<LiteralContext *>(
            _tracker.createInstance<BasicParser::BoolTContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(192);
        match(BasicParser::TRUE);
        break;
      }

      case BasicParser::FALSE: {
        _localctx = dynamic_cast<LiteralContext *>(
            _tracker.createInstance<BasicParser::BoolFContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(193);
        match(BasicParser::FALSE);
        break;
      }

      case BasicParser::DEC_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(
            _tracker.createInstance<BasicParser::IntDecContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(194);
        match(BasicParser::DEC_LITERAL);
        break;
      }

      case BasicParser::HEX_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(
            _tracker.createInstance<BasicParser::IntHexContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(195);
        match(BasicParser::HEX_LITERAL);
        break;
      }

      case BasicParser::OCT_LITERAL: {
        _localctx = dynamic_cast<LiteralContext *>(
            _tracker.createInstance<BasicParser::IntOctContext>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(196);
        match(BasicParser::OCT_LITERAL);
        break;
      }

      default:
        throw NoViableAltException(this);
    }

  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext
//------------------------------------------------------------------

BasicParser::ExprContext::ExprContext(ParserRuleContext *parent,
                                      size_t invokingState)
    : ParserRuleContext(parent, invokingState) {}

size_t BasicParser::ExprContext::getRuleIndex() const {
  return BasicParser::RuleExpr;
}

void BasicParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AddContext
//------------------------------------------------------------------

std::vector<BasicParser::ExprContext *> BasicParser::AddContext::expr() {
  return getRuleContexts<BasicParser::ExprContext>();
}

BasicParser::ExprContext *BasicParser::AddContext::expr(size_t i) {
  return getRuleContext<BasicParser::ExprContext>(i);
}

tree::TerminalNode *BasicParser::AddContext::ADD() {
  return getToken(BasicParser::ADD, 0);
}

tree::TerminalNode *BasicParser::AddContext::SUB() {
  return getToken(BasicParser::SUB, 0);
}

BasicParser::AddContext::AddContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any BasicParser::AddContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitAdd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CastContext
//------------------------------------------------------------------

BasicParser::ExprContext *BasicParser::CastContext::expr() {
  return getRuleContext<BasicParser::ExprContext>(0);
}

BasicParser::TypeDeclContext *BasicParser::CastContext::typeDecl() {
  return getRuleContext<BasicParser::TypeDeclContext>(0);
}

BasicParser::CastContext::CastContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any BasicParser::CastContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitCast(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AsgContext
//------------------------------------------------------------------

BasicParser::LValContext *BasicParser::AsgContext::lVal() {
  return getRuleContext<BasicParser::LValContext>(0);
}

tree::TerminalNode *BasicParser::AsgContext::ASSIGN() {
  return getToken(BasicParser::ASSIGN, 0);
}

BasicParser::ExprContext *BasicParser::AsgContext::expr() {
  return getRuleContext<BasicParser::ExprContext>(0);
}

BasicParser::AsgContext::AsgContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any BasicParser::AsgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitAsg(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulContext
//------------------------------------------------------------------

std::vector<BasicParser::ExprContext *> BasicParser::MulContext::expr() {
  return getRuleContexts<BasicParser::ExprContext>();
}

BasicParser::ExprContext *BasicParser::MulContext::expr(size_t i) {
  return getRuleContext<BasicParser::ExprContext>(i);
}

tree::TerminalNode *BasicParser::MulContext::MUL() {
  return getToken(BasicParser::MUL, 0);
}

tree::TerminalNode *BasicParser::MulContext::DIV() {
  return getToken(BasicParser::DIV, 0);
}

tree::TerminalNode *BasicParser::MulContext::MOD() {
  return getToken(BasicParser::MOD, 0);
}

BasicParser::MulContext::MulContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any BasicParser::MulContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitMul(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LitExprContext
//------------------------------------------------------------------

BasicParser::LiteralContext *BasicParser::LitExprContext::literal() {
  return getRuleContext<BasicParser::LiteralContext>(0);
}

BasicParser::LitExprContext::LitExprContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any BasicParser::LitExprContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitLitExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LvalExprContext
//------------------------------------------------------------------

BasicParser::LValContext *BasicParser::LvalExprContext::lVal() {
  return getRuleContext<BasicParser::LValContext>(0);
}

BasicParser::LvalExprContext::LvalExprContext(ExprContext *ctx) {
  copyFrom(ctx);
}

antlrcpp::Any BasicParser::LvalExprContext::accept(
    tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicParserVisitor *>(visitor))
    return parserVisitor->visitLvalExpr(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::ExprContext *BasicParser::expr() { return expr(0); }

BasicParser::ExprContext *BasicParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  BasicParser::ExprContext *_localctx =
      _tracker.createInstance<ExprContext>(_ctx, parentState);
  BasicParser::ExprContext *previousContext = _localctx;
  (void)previousContext;  // Silence compiler, in case the context is not used
                          // by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, BasicParser::RuleExpr, precedence);

  size_t _la = 0;

  auto onExit = finally([=] { unrollRecursionContexts(parentContext); });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(206);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
        _input, 22, _ctx)) {
      case 1: {
        _localctx = _tracker.createInstance<LitExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(200);
        literal();
        break;
      }

      case 2: {
        _localctx = _tracker.createInstance<LvalExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(201);
        lVal(0);
        break;
      }

      case 3: {
        _localctx = _tracker.createInstance<AsgContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(202);
        lVal(0);
        setState(203);
        match(BasicParser::ASSIGN);
        setState(204);
        expr(1);
        break;
      }
    }
    _ctx->stop = _input->LT(-1);
    setState(218);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24,
                                                                     _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty()) triggerExitRuleEvent();
        previousContext = _localctx;
        setState(216);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
            _input, 23, _ctx)) {
          case 1: {
            auto newContext = _tracker.createInstance<MulContext>(
                _tracker.createInstance<ExprContext>(parentContext,
                                                     parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpr);
            setState(208);

            if (!(precpred(_ctx, 3)))
              throw FailedPredicateException(this, "precpred(_ctx, 3)");
            setState(209);
            dynamic_cast<MulContext *>(_localctx)->op = _input->LT(1);
            _la = _input->LA(1);
            if (!((((_la & ~0x3fULL) == 0) &&
                   ((1ULL << _la) &
                    ((1ULL << BasicParser::MUL) | (1ULL << BasicParser::DIV) |
                     (1ULL << BasicParser::MOD))) != 0))) {
              dynamic_cast<MulContext *>(_localctx)->op =
                  _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(210);
            expr(4);
            break;
          }

          case 2: {
            auto newContext = _tracker.createInstance<AddContext>(
                _tracker.createInstance<ExprContext>(parentContext,
                                                     parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpr);
            setState(211);

            if (!(precpred(_ctx, 2)))
              throw FailedPredicateException(this, "precpred(_ctx, 2)");
            setState(212);
            dynamic_cast<AddContext *>(_localctx)->op = _input->LT(1);
            _la = _input->LA(1);
            if (!(_la == BasicParser::ADD

                  || _la == BasicParser::SUB)) {
              dynamic_cast<AddContext *>(_localctx)->op =
                  _errHandler->recoverInline(this);
            } else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(213);
            expr(3);
            break;
          }

          case 3: {
            auto newContext = _tracker.createInstance<CastContext>(
                _tracker.createInstance<ExprContext>(parentContext,
                                                     parentState));
            _localctx = newContext;
            pushNewRecursionContext(newContext, startState, RuleExpr);
            setState(214);

            if (!(precpred(_ctx, 6)))
              throw FailedPredicateException(this, "precpred(_ctx, 6)");
            setState(215);
            typeDecl();
            break;
          }
        }
      }
      setState(220);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(
          _input, 24, _ctx);
    }
  } catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool BasicParser::sempred(RuleContext *context, size_t ruleIndex,
                          size_t predicateIndex) {
  switch (ruleIndex) {
    case 18:
      return lValSempred(dynamic_cast<LValContext *>(context), predicateIndex);
    case 20:
      return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

    default:
      break;
  }
  return true;
}

bool BasicParser::lValSempred(LValContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0:
      return precpred(_ctx, 4);
    case 1:
      return precpred(_ctx, 3);
    case 2:
      return precpred(_ctx, 2);

    default:
      break;
  }
  return true;
}

bool BasicParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3:
      return precpred(_ctx, 3);
    case 4:
      return precpred(_ctx, 2);
    case 5:
      return precpred(_ctx, 6);

    default:
      break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> BasicParser::_decisionToDFA;
atn::PredictionContextCache BasicParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN BasicParser::_atn;
std::vector<uint16_t> BasicParser::_serializedATN;

std::vector<std::string> BasicParser::_ruleNames = {
    "file",        "statements", "retStmt",  "blckStmt",      "exprStmt",
    "primTypes",   "varType",    "typeDecl", "varDecl",       "varDef",
    "varParam",    "argList",    "recDecl",  "funcSignature", "funcDef",
    "extFuncDecl", "funcParams", "funcCall", "lVal",          "literal",
    "expr"};

std::vector<std::string> BasicParser::_literalNames = {
    "",       "'var'",  "'return'", "'proc'", "'record'", "'extern'",
    "'this'", "'void'", "",         "",       "'string'", "",
    "'bool'", "'.'",    "':'",      "';'",    "','",      "'{'",
    "'}'",    "'('",    "')'",      "'='",    "'+'",      "'-'",
    "'*'",    "'/'",    "'%'",      "",       "",         "'true'",
    "'false'"};

std::vector<std::string> BasicParser::_symbolicNames = {
    "",
    "VAR",
    "RETURN",
    "PROC",
    "RECORD",
    "EXTERN",
    "THIS",
    "VOID",
    "INT",
    "UINT",
    "STRING",
    "REAL",
    "BOOL",
    "DOT",
    "COLON",
    "SEMICOLON",
    "COMMA",
    "OPEN_BRACES",
    "CLOSE_BRACES",
    "OPEN_PARENTHESES",
    "CLOSE_PARENTHESES",
    "ASSIGN",
    "ADD",
    "SUB",
    "MUL",
    "DIV",
    "MOD",
    "IDENTIFIER",
    "STRING_LITERAL",
    "TRUE",
    "FALSE",
    "DEC_LITERAL",
    "HEX_LITERAL",
    "OCT_LITERAL",
    "REAL_LITERAL",
    "SINGLE_LINE_COMMENT",
    "WHITESPACE",
    "MULTILINE_COMMENT_START",
    "MULTILINE_COMMENT_END",
    "COMMENT_START",
    "COMMENT_END",
    "ANYCHAR"};

dfa::Vocabulary BasicParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> BasicParser::_tokenNames;

BasicParser::Initializer::Initializer() {
  for (size_t i = 0; i < _symbolicNames.size(); ++i) {
    std::string name = _vocabulary.getLiteralName(i);
    if (name.empty()) {
      name = _vocabulary.getSymbolicName(i);
    }

    if (name.empty()) {
      _tokenNames.push_back("<INVALID>");
    } else {
      _tokenNames.push_back(name);
    }
  }

  _serializedATN = {
      0x3,  0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964,
      0x3,  0x2b,   0xe0,   0x4,    0x2,    0x9,    0x2,    0x4,    0x3,
      0x9,  0x3,    0x4,    0x4,    0x9,    0x4,    0x4,    0x5,    0x9,
      0x5,  0x4,    0x6,    0x9,    0x6,    0x4,    0x7,    0x9,    0x7,
      0x4,  0x8,    0x9,    0x8,    0x4,    0x9,    0x9,    0x9,    0x4,
      0xa,  0x9,    0xa,    0x4,    0xb,    0x9,    0xb,    0x4,    0xc,
      0x9,  0xc,    0x4,    0xd,    0x9,    0xd,    0x4,    0xe,    0x9,
      0xe,  0x4,    0xf,    0x9,    0xf,    0x4,    0x10,   0x9,    0x10,
      0x4,  0x11,   0x9,    0x11,   0x4,    0x12,   0x9,    0x12,   0x4,
      0x13, 0x9,    0x13,   0x4,    0x14,   0x9,    0x14,   0x4,    0x15,
      0x9,  0x15,   0x4,    0x16,   0x9,    0x16,   0x3,    0x2,    0x3,
      0x2,  0x3,    0x2,    0x3,    0x2,    0x3,    0x2,    0x7,    0x2,
      0x32, 0xa,    0x2,    0xc,    0x2,    0xe,    0x2,    0x35,   0xb,
      0x2,  0x3,    0x3,    0x3,    0x3,    0x5,    0x3,    0x39,   0xa,
      0x3,  0x3,    0x4,    0x3,    0x4,    0x3,    0x4,    0x3,    0x4,
      0x3,  0x5,    0x3,    0x5,    0x3,    0x5,    0x3,    0x5,    0x7,
      0x5,  0x43,   0xa,    0x5,    0xc,    0x5,    0xe,    0x5,    0x46,
      0xb,  0x5,    0x3,    0x5,    0x3,    0x5,    0x3,    0x6,    0x3,
      0x6,  0x3,    0x6,    0x3,    0x7,    0x3,    0x7,    0x3,    0x8,
      0x3,  0x8,    0x5,    0x8,    0x51,   0xa,    0x8,    0x3,    0x9,
      0x3,  0x9,    0x3,    0x9,    0x3,    0xa,    0x3,    0xa,    0x3,
      0xa,  0x7,    0xa,    0x59,   0xa,    0xa,    0xc,    0xa,    0xe,
      0xa,  0x5c,   0xb,    0xa,    0x3,    0xa,    0x3,    0xa,    0x5,
      0xa,  0x60,   0xa,    0xa,    0x3,    0xa,    0x3,    0xa,    0x5,
      0xa,  0x64,   0xa,    0xa,    0x3,    0xb,    0x3,    0xb,    0x3,
      0xb,  0x3,    0xb,    0x5,    0xb,    0x6a,   0xa,    0xb,    0x3,
      0xb,  0x3,    0xb,    0x3,    0xc,    0x3,    0xc,    0x3,    0xc,
      0x3,  0xd,    0x3,    0xd,    0x3,    0xd,    0x7,    0xd,    0x74,
      0xa,  0xd,    0xc,    0xd,    0xe,    0xd,    0x77,   0xb,    0xd,
      0x3,  0xe,    0x3,    0xe,    0x3,    0xe,    0x3,    0xe,    0x3,
      0xe,  0x3,    0xe,    0x3,    0xe,    0x3,    0xe,    0x7,    0xe,
      0x81, 0xa,    0xe,    0xc,    0xe,    0xe,    0xe,    0x84,   0xb,
      0xe,  0x3,    0xe,    0x3,    0xe,    0x3,    0xf,    0x3,    0xf,
      0x3,  0xf,    0x3,    0xf,    0x5,    0xf,    0x8c,   0xa,    0xf,
      0x3,  0xf,    0x3,    0xf,    0x5,    0xf,    0x90,   0xa,    0xf,
      0x3,  0x10,   0x3,    0x10,   0x3,    0x10,   0x3,    0x11,   0x3,
      0x11, 0x5,    0x11,   0x97,   0xa,    0x11,   0x3,    0x11,   0x3,
      0x11, 0x3,    0x11,   0x3,    0x12,   0x3,    0x12,   0x3,    0x12,
      0x7,  0x12,   0x9f,   0xa,    0x12,   0xc,    0x12,   0xe,    0x12,
      0xa2, 0xb,    0x12,   0x3,    0x13,   0x3,    0x13,   0x5,    0x13,
      0xa6, 0xa,    0x13,   0x3,    0x13,   0x3,    0x13,   0x3,    0x14,
      0x3,  0x14,   0x3,    0x14,   0x3,    0x14,   0x3,    0x14,   0x3,
      0x14, 0x3,    0x14,   0x5,    0x14,   0xb1,   0xa,    0x14,   0x3,
      0x14, 0x3,    0x14,   0x3,    0x14,   0x3,    0x14,   0x3,    0x14,
      0x3,  0x14,   0x3,    0x14,   0x3,    0x14,   0x3,    0x14,   0x7,
      0x14, 0xbc,   0xa,    0x14,   0xc,    0x14,   0xe,    0x14,   0xbf,
      0xb,  0x14,   0x3,    0x15,   0x3,    0x15,   0x3,    0x15,   0x3,
      0x15, 0x3,    0x15,   0x3,    0x15,   0x3,    0x15,   0x5,    0x15,
      0xc8, 0xa,    0x15,   0x3,    0x16,   0x3,    0x16,   0x3,    0x16,
      0x3,  0x16,   0x3,    0x16,   0x3,    0x16,   0x3,    0x16,   0x5,
      0x16, 0xd1,   0xa,    0x16,   0x3,    0x16,   0x3,    0x16,   0x3,
      0x16, 0x3,    0x16,   0x3,    0x16,   0x3,    0x16,   0x3,    0x16,
      0x3,  0x16,   0x7,    0x16,   0xdb,   0xa,    0x16,   0xc,    0x16,
      0xe,  0x16,   0xde,   0xb,    0x16,   0x3,    0x16,   0x2,    0x4,
      0x26, 0x2a,   0x17,   0x2,    0x4,    0x6,    0x8,    0xa,    0xc,
      0xe,  0x10,   0x12,   0x14,   0x16,   0x18,   0x1a,   0x1c,   0x1e,
      0x20, 0x22,   0x24,   0x26,   0x28,   0x2a,   0x2,    0x5,    0x3,
      0x2,  0xa,    0xe,    0x3,    0x2,    0x1a,   0x1c,   0x3,    0x2,
      0x18, 0x19,   0x2,    0xf0,   0x2,    0x33,   0x3,    0x2,    0x2,
      0x2,  0x4,    0x38,   0x3,    0x2,    0x2,    0x2,    0x6,    0x3a,
      0x3,  0x2,    0x2,    0x2,    0x8,    0x3e,   0x3,    0x2,    0x2,
      0x2,  0xa,    0x49,   0x3,    0x2,    0x2,    0x2,    0xc,    0x4c,
      0x3,  0x2,    0x2,    0x2,    0xe,    0x50,   0x3,    0x2,    0x2,
      0x2,  0x10,   0x52,   0x3,    0x2,    0x2,    0x2,    0x12,   0x55,
      0x3,  0x2,    0x2,    0x2,    0x14,   0x65,   0x3,    0x2,    0x2,
      0x2,  0x16,   0x6d,   0x3,    0x2,    0x2,    0x2,    0x18,   0x70,
      0x3,  0x2,    0x2,    0x2,    0x1a,   0x78,   0x3,    0x2,    0x2,
      0x2,  0x1c,   0x87,   0x3,    0x2,    0x2,    0x2,    0x1e,   0x91,
      0x3,  0x2,    0x2,    0x2,    0x20,   0x94,   0x3,    0x2,    0x2,
      0x2,  0x22,   0x9b,   0x3,    0x2,    0x2,    0x2,    0x24,   0xa3,
      0x3,  0x2,    0x2,    0x2,    0x26,   0xb0,   0x3,    0x2,    0x2,
      0x2,  0x28,   0xc7,   0x3,    0x2,    0x2,    0x2,    0x2a,   0xd0,
      0x3,  0x2,    0x2,    0x2,    0x2c,   0x32,   0x5,    0x14,   0xb,
      0x2,  0x2d,   0x32,   0x5,    0xa,    0x6,    0x2,    0x2e,   0x32,
      0x5,  0x1e,   0x10,   0x2,    0x2f,   0x32,   0x5,    0x20,   0x11,
      0x2,  0x30,   0x32,   0x5,    0x1a,   0xe,    0x2,    0x31,   0x2c,
      0x3,  0x2,    0x2,    0x2,    0x31,   0x2d,   0x3,    0x2,    0x2,
      0x2,  0x31,   0x2e,   0x3,    0x2,    0x2,    0x2,    0x31,   0x2f,
      0x3,  0x2,    0x2,    0x2,    0x31,   0x30,   0x3,    0x2,    0x2,
      0x2,  0x32,   0x35,   0x3,    0x2,    0x2,    0x2,    0x33,   0x31,
      0x3,  0x2,    0x2,    0x2,    0x33,   0x34,   0x3,    0x2,    0x2,
      0x2,  0x34,   0x3,    0x3,    0x2,    0x2,    0x2,    0x35,   0x33,
      0x3,  0x2,    0x2,    0x2,    0x36,   0x39,   0x5,    0xa,    0x6,
      0x2,  0x37,   0x39,   0x5,    0x8,    0x5,    0x2,    0x38,   0x36,
      0x3,  0x2,    0x2,    0x2,    0x38,   0x37,   0x3,    0x2,    0x2,
      0x2,  0x39,   0x5,    0x3,    0x2,    0x2,    0x2,    0x3a,   0x3b,
      0x7,  0x4,    0x2,    0x2,    0x3b,   0x3c,   0x5,    0x2a,   0x16,
      0x2,  0x3c,   0x3d,   0x7,    0x11,   0x2,    0x2,    0x3d,   0x7,
      0x3,  0x2,    0x2,    0x2,    0x3e,   0x44,   0x7,    0x13,   0x2,
      0x2,  0x3f,   0x43,   0x5,    0x14,   0xb,    0x2,    0x40,   0x43,
      0x5,  0xa,    0x6,    0x2,    0x41,   0x43,   0x5,    0x6,    0x4,
      0x2,  0x42,   0x3f,   0x3,    0x2,    0x2,    0x2,    0x42,   0x40,
      0x3,  0x2,    0x2,    0x2,    0x42,   0x41,   0x3,    0x2,    0x2,
      0x2,  0x43,   0x46,   0x3,    0x2,    0x2,    0x2,    0x44,   0x42,
      0x3,  0x2,    0x2,    0x2,    0x44,   0x45,   0x3,    0x2,    0x2,
      0x2,  0x45,   0x47,   0x3,    0x2,    0x2,    0x2,    0x46,   0x44,
      0x3,  0x2,    0x2,    0x2,    0x47,   0x48,   0x7,    0x14,   0x2,
      0x2,  0x48,   0x9,    0x3,    0x2,    0x2,    0x2,    0x49,   0x4a,
      0x5,  0x2a,   0x16,   0x2,    0x4a,   0x4b,   0x7,    0x11,   0x2,
      0x2,  0x4b,   0xb,    0x3,    0x2,    0x2,    0x2,    0x4c,   0x4d,
      0x9,  0x2,    0x2,    0x2,    0x4d,   0xd,    0x3,    0x2,    0x2,
      0x2,  0x4e,   0x51,   0x7,    0x1d,   0x2,    0x2,    0x4f,   0x51,
      0x5,  0xc,    0x7,    0x2,    0x50,   0x4e,   0x3,    0x2,    0x2,
      0x2,  0x50,   0x4f,   0x3,    0x2,    0x2,    0x2,    0x51,   0xf,
      0x3,  0x2,    0x2,    0x2,    0x52,   0x53,   0x7,    0x10,   0x2,
      0x2,  0x53,   0x54,   0x5,    0xe,    0x8,    0x2,    0x54,   0x11,
      0x3,  0x2,    0x2,    0x2,    0x55,   0x5a,   0x7,    0x1d,   0x2,
      0x2,  0x56,   0x57,   0x7,    0x12,   0x2,    0x2,    0x57,   0x59,
      0x7,  0x1d,   0x2,    0x2,    0x58,   0x56,   0x3,    0x2,    0x2,
      0x2,  0x59,   0x5c,   0x3,    0x2,    0x2,    0x2,    0x5a,   0x58,
      0x3,  0x2,    0x2,    0x2,    0x5a,   0x5b,   0x3,    0x2,    0x2,
      0x2,  0x5b,   0x63,   0x3,    0x2,    0x2,    0x2,    0x5c,   0x5a,
      0x3,  0x2,    0x2,    0x2,    0x5d,   0x64,   0x5,    0x10,   0x9,
      0x2,  0x5e,   0x60,   0x5,    0x10,   0x9,    0x2,    0x5f,   0x5e,
      0x3,  0x2,    0x2,    0x2,    0x5f,   0x60,   0x3,    0x2,    0x2,
      0x2,  0x60,   0x61,   0x3,    0x2,    0x2,    0x2,    0x61,   0x62,
      0x7,  0x17,   0x2,    0x2,    0x62,   0x64,   0x5,    0x2a,   0x16,
      0x2,  0x63,   0x5d,   0x3,    0x2,    0x2,    0x2,    0x63,   0x5f,
      0x3,  0x2,    0x2,    0x2,    0x64,   0x13,   0x3,    0x2,    0x2,
      0x2,  0x65,   0x66,   0x7,    0x3,    0x2,    0x2,    0x66,   0x69,
      0x5,  0x12,   0xa,    0x2,    0x67,   0x68,   0x7,    0x12,   0x2,
      0x2,  0x68,   0x6a,   0x5,    0x12,   0xa,    0x2,    0x69,   0x67,
      0x3,  0x2,    0x2,    0x2,    0x69,   0x6a,   0x3,    0x2,    0x2,
      0x2,  0x6a,   0x6b,   0x3,    0x2,    0x2,    0x2,    0x6b,   0x6c,
      0x7,  0x11,   0x2,    0x2,    0x6c,   0x15,   0x3,    0x2,    0x2,
      0x2,  0x6d,   0x6e,   0x7,    0x1d,   0x2,    0x2,    0x6e,   0x6f,
      0x5,  0x10,   0x9,    0x2,    0x6f,   0x17,   0x3,    0x2,    0x2,
      0x2,  0x70,   0x75,   0x5,    0x16,   0xc,    0x2,    0x71,   0x72,
      0x7,  0x12,   0x2,    0x2,    0x72,   0x74,   0x5,    0x16,   0xc,
      0x2,  0x73,   0x71,   0x3,    0x2,    0x2,    0x2,    0x74,   0x77,
      0x3,  0x2,    0x2,    0x2,    0x75,   0x73,   0x3,    0x2,    0x2,
      0x2,  0x75,   0x76,   0x3,    0x2,    0x2,    0x2,    0x76,   0x19,
      0x3,  0x2,    0x2,    0x2,    0x77,   0x75,   0x3,    0x2,    0x2,
      0x2,  0x78,   0x79,   0x7,    0x6,    0x2,    0x2,    0x79,   0x7a,
      0x7,  0x1d,   0x2,    0x2,    0x7a,   0x82,   0x7,    0x13,   0x2,
      0x2,  0x7b,   0x7c,   0x7,    0x3,    0x2,    0x2,    0x7c,   0x7d,
      0x5,  0x16,   0xc,    0x2,    0x7d,   0x7e,   0x7,    0x11,   0x2,
      0x2,  0x7e,   0x81,   0x3,    0x2,    0x2,    0x2,    0x7f,   0x81,
      0x5,  0x1e,   0x10,   0x2,    0x80,   0x7b,   0x3,    0x2,    0x2,
      0x2,  0x80,   0x7f,   0x3,    0x2,    0x2,    0x2,    0x81,   0x84,
      0x3,  0x2,    0x2,    0x2,    0x82,   0x80,   0x3,    0x2,    0x2,
      0x2,  0x82,   0x83,   0x3,    0x2,    0x2,    0x2,    0x83,   0x85,
      0x3,  0x2,    0x2,    0x2,    0x84,   0x82,   0x3,    0x2,    0x2,
      0x2,  0x85,   0x86,   0x7,    0x14,   0x2,    0x2,    0x86,   0x1b,
      0x3,  0x2,    0x2,    0x2,    0x87,   0x88,   0x7,    0x5,    0x2,
      0x2,  0x88,   0x89,   0x7,    0x1d,   0x2,    0x2,    0x89,   0x8b,
      0x7,  0x15,   0x2,    0x2,    0x8a,   0x8c,   0x5,    0x18,   0xd,
      0x2,  0x8b,   0x8a,   0x3,    0x2,    0x2,    0x2,    0x8b,   0x8c,
      0x3,  0x2,    0x2,    0x2,    0x8c,   0x8d,   0x3,    0x2,    0x2,
      0x2,  0x8d,   0x8f,   0x7,    0x16,   0x2,    0x2,    0x8e,   0x90,
      0x5,  0x10,   0x9,    0x2,    0x8f,   0x8e,   0x3,    0x2,    0x2,
      0x2,  0x8f,   0x90,   0x3,    0x2,    0x2,    0x2,    0x90,   0x1d,
      0x3,  0x2,    0x2,    0x2,    0x91,   0x92,   0x5,    0x1c,   0xf,
      0x2,  0x92,   0x93,   0x5,    0x8,    0x5,    0x2,    0x93,   0x1f,
      0x3,  0x2,    0x2,    0x2,    0x94,   0x96,   0x7,    0x7,    0x2,
      0x2,  0x95,   0x97,   0x7,    0x1d,   0x2,    0x2,    0x96,   0x95,
      0x3,  0x2,    0x2,    0x2,    0x96,   0x97,   0x3,    0x2,    0x2,
      0x2,  0x97,   0x98,   0x3,    0x2,    0x2,    0x2,    0x98,   0x99,
      0x5,  0x1c,   0xf,    0x2,    0x99,   0x9a,   0x7,    0x11,   0x2,
      0x2,  0x9a,   0x21,   0x3,    0x2,    0x2,    0x2,    0x9b,   0xa0,
      0x5,  0x2a,   0x16,   0x2,    0x9c,   0x9d,   0x7,    0x12,   0x2,
      0x2,  0x9d,   0x9f,   0x5,    0x2a,   0x16,   0x2,    0x9e,   0x9c,
      0x3,  0x2,    0x2,    0x2,    0x9f,   0xa2,   0x3,    0x2,    0x2,
      0x2,  0xa0,   0x9e,   0x3,    0x2,    0x2,    0x2,    0xa0,   0xa1,
      0x3,  0x2,    0x2,    0x2,    0xa1,   0x23,   0x3,    0x2,    0x2,
      0x2,  0xa2,   0xa0,   0x3,    0x2,    0x2,    0x2,    0xa3,   0xa5,
      0x7,  0x15,   0x2,    0x2,    0xa4,   0xa6,   0x5,    0x22,   0x12,
      0x2,  0xa5,   0xa4,   0x3,    0x2,    0x2,    0x2,    0xa5,   0xa6,
      0x3,  0x2,    0x2,    0x2,    0xa6,   0xa7,   0x3,    0x2,    0x2,
      0x2,  0xa7,   0xa8,   0x7,    0x16,   0x2,    0x2,    0xa8,   0x25,
      0x3,  0x2,    0x2,    0x2,    0xa9,   0xaa,   0x8,    0x14,   0x1,
      0x2,  0xaa,   0xb1,   0x7,    0x8,    0x2,    0x2,    0xab,   0xb1,
      0x7,  0x1d,   0x2,    0x2,    0xac,   0xad,   0x7,    0x15,   0x2,
      0x2,  0xad,   0xae,   0x5,    0x2a,   0x16,   0x2,    0xae,   0xaf,
      0x7,  0x16,   0x2,    0x2,    0xaf,   0xb1,   0x3,    0x2,    0x2,
      0x2,  0xb0,   0xa9,   0x3,    0x2,    0x2,    0x2,    0xb0,   0xab,
      0x3,  0x2,    0x2,    0x2,    0xb0,   0xac,   0x3,    0x2,    0x2,
      0x2,  0xb1,   0xbd,   0x3,    0x2,    0x2,    0x2,    0xb2,   0xb3,
      0xc,  0x6,    0x2,    0x2,    0xb3,   0xb4,   0x7,    0xf,    0x2,
      0x2,  0xb4,   0xb5,   0x7,    0x1d,   0x2,    0x2,    0xb5,   0xbc,
      0x5,  0x24,   0x13,   0x2,    0xb6,   0xb7,   0xc,    0x5,    0x2,
      0x2,  0xb7,   0xb8,   0x7,    0xf,    0x2,    0x2,    0xb8,   0xbc,
      0x7,  0x1d,   0x2,    0x2,    0xb9,   0xba,   0xc,    0x4,    0x2,
      0x2,  0xba,   0xbc,   0x5,    0x24,   0x13,   0x2,    0xbb,   0xb2,
      0x3,  0x2,    0x2,    0x2,    0xbb,   0xb6,   0x3,    0x2,    0x2,
      0x2,  0xbb,   0xb9,   0x3,    0x2,    0x2,    0x2,    0xbc,   0xbf,
      0x3,  0x2,    0x2,    0x2,    0xbd,   0xbb,   0x3,    0x2,    0x2,
      0x2,  0xbd,   0xbe,   0x3,    0x2,    0x2,    0x2,    0xbe,   0x27,
      0x3,  0x2,    0x2,    0x2,    0xbf,   0xbd,   0x3,    0x2,    0x2,
      0x2,  0xc0,   0xc8,   0x7,    0x1e,   0x2,    0x2,    0xc1,   0xc8,
      0x7,  0x24,   0x2,    0x2,    0xc2,   0xc8,   0x7,    0x1f,   0x2,
      0x2,  0xc3,   0xc8,   0x7,    0x20,   0x2,    0x2,    0xc4,   0xc8,
      0x7,  0x21,   0x2,    0x2,    0xc5,   0xc8,   0x7,    0x22,   0x2,
      0x2,  0xc6,   0xc8,   0x7,    0x23,   0x2,    0x2,    0xc7,   0xc0,
      0x3,  0x2,    0x2,    0x2,    0xc7,   0xc1,   0x3,    0x2,    0x2,
      0x2,  0xc7,   0xc2,   0x3,    0x2,    0x2,    0x2,    0xc7,   0xc3,
      0x3,  0x2,    0x2,    0x2,    0xc7,   0xc4,   0x3,    0x2,    0x2,
      0x2,  0xc7,   0xc5,   0x3,    0x2,    0x2,    0x2,    0xc7,   0xc6,
      0x3,  0x2,    0x2,    0x2,    0xc8,   0x29,   0x3,    0x2,    0x2,
      0x2,  0xc9,   0xca,   0x8,    0x16,   0x1,    0x2,    0xca,   0xd1,
      0x5,  0x28,   0x15,   0x2,    0xcb,   0xd1,   0x5,    0x26,   0x14,
      0x2,  0xcc,   0xcd,   0x5,    0x26,   0x14,   0x2,    0xcd,   0xce,
      0x7,  0x17,   0x2,    0x2,    0xce,   0xcf,   0x5,    0x2a,   0x16,
      0x3,  0xcf,   0xd1,   0x3,    0x2,    0x2,    0x2,    0xd0,   0xc9,
      0x3,  0x2,    0x2,    0x2,    0xd0,   0xcb,   0x3,    0x2,    0x2,
      0x2,  0xd0,   0xcc,   0x3,    0x2,    0x2,    0x2,    0xd1,   0xdc,
      0x3,  0x2,    0x2,    0x2,    0xd2,   0xd3,   0xc,    0x5,    0x2,
      0x2,  0xd3,   0xd4,   0x9,    0x3,    0x2,    0x2,    0xd4,   0xdb,
      0x5,  0x2a,   0x16,   0x6,    0xd5,   0xd6,   0xc,    0x4,    0x2,
      0x2,  0xd6,   0xd7,   0x9,    0x4,    0x2,    0x2,    0xd7,   0xdb,
      0x5,  0x2a,   0x16,   0x5,    0xd8,   0xd9,   0xc,    0x8,    0x2,
      0x2,  0xd9,   0xdb,   0x5,    0x10,   0x9,    0x2,    0xda,   0xd2,
      0x3,  0x2,    0x2,    0x2,    0xda,   0xd5,   0x3,    0x2,    0x2,
      0x2,  0xda,   0xd8,   0x3,    0x2,    0x2,    0x2,    0xdb,   0xde,
      0x3,  0x2,    0x2,    0x2,    0xdc,   0xda,   0x3,    0x2,    0x2,
      0x2,  0xdc,   0xdd,   0x3,    0x2,    0x2,    0x2,    0xdd,   0x2b,
      0x3,  0x2,    0x2,    0x2,    0xde,   0xdc,   0x3,    0x2,    0x2,
      0x2,  0x1b,   0x31,   0x33,   0x38,   0x42,   0x44,   0x50,   0x5a,
      0x5f, 0x63,   0x69,   0x75,   0x80,   0x82,   0x8b,   0x8f,   0x96,
      0xa0, 0xa5,   0xb0,   0xbb,   0xbd,   0xc7,   0xd0,   0xda,   0xdc,
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) {
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

BasicParser::Initializer BasicParser::_init;
