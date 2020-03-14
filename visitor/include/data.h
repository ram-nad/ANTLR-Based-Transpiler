#include <string>
#include <vector>
#include <grammar/BasicParser.h>
#include <definitions.h>

#ifndef CH_DATA_H
#define CH_DATA_H CH_DATA_H

namespace ch2c {

struct expressionData {
  Type type;
  std::string expression;
  bool assignable;
};

struct variableDeclaration {
  Type type;
  std::string name;
  std::size_t line;
  std::size_t column;
};

struct variableDefinition {
  Type type;
  std::string name;
  std::string initializer;
};

struct functionContext {
  functionType type;
  BasicParser::BlckStmtContext* blckStmt;
  bool valid;
};

}  // namespace ch2c

#endif