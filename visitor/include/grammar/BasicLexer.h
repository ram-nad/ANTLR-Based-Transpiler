
// Generated from BasicLexer.g4 by ANTLR 4.8

#pragma once

#include <antlr4-runtime/antlr4-runtime.h>

namespace ch2c {

class BasicLexer : public antlr4::Lexer {
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

  enum { MULTILINE_COMMENT = 1 };

  BasicLexer(antlr4::CharStream* input);
  ~BasicLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames()
      const override;  // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

 private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace ch2c
