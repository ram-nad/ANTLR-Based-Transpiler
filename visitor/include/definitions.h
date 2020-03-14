#include <string>
#include <vector>
#include <grammar/BasicParser.h>

#ifndef CH_DEFINITION_H
#define CH_DEFINITION_H CH_DEFINITION_H

namespace ch2c {

using Type = int;

struct variableType {
  Type typeIndex;
  std::string name;
};

struct functionType {
  std::string functionName;
  std::string functionPrintName;
  Type returnType;
  std::vector<variableType> parameterList;
  std::map<std::string, Type> localVariables;
};

struct recordType {
  int typeIndex;
  std::string name;
  std::map<std::string, variableType> members;
  std::map<std::string, functionType> methods;
};

}  // namespace ch2c

#endif