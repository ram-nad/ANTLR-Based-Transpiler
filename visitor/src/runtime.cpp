#include <visitor.h>

namespace ch2c {

const std::string& Visitor::getPrintName(Type type) {
  if (type < Visitor::BUILT_IN_TYPE_COUNT) {
    return Visitor::BUILT_IN_TYPES_PRINT[type];
  } else {
    return recordsList[type - Visitor::BUILT_IN_TYPE_COUNT].name;
  }
}

const std::string& Visitor::getName(Type type) {
  if (type < Visitor::BUILT_IN_TYPE_COUNT) {
    return Visitor::BUILT_IN_TYPES[type];
  } else {
    return recordsList[type - Visitor::BUILT_IN_TYPE_COUNT].name;
  }
}

bool Visitor::checkUsableName(const std::string& name) {
  return typeMap.find(name) == typeMap.end() &&
         functionsList.find(name) == functionsList.end();
}

bool Visitor::checkUsableIdentifier(const std::string& name) {
  if (typeMap.find(name) != typeMap.end() ||
      functionsList.find(name) != functionsList.end()) {
    return false;
  } else {
    if (currentFunction != nullptr) {
      currentFunction->localVariables.find(name) ==
          currentFunction->localVariables.end();
    } else {
      return globalVariables.find(name) == globalVariables.end();
    }
  }
}

bool Visitor::checkExistVariable(const std::string& name) {
  if (currentFunction != nullptr) {
    currentFunction->localVariables.find(name) !=
            currentFunction->localVariables.end() ||
        globalVariables.find(name) != globalVariables.end();
  } else {
    return globalVariables.find(name) != globalVariables.end();
  }
}

void Visitor::insertVariable(const std::string& name, Type type) {
  if (currentFunction == nullptr) {
    globalVariables.insert(std::make_pair(name, type));
  } else {
    currentFunction->localVariables.insert(std::make_pair(name, type));
  }
}

bool Visitor::checkExistFunction(const std::string& name) {
  return functionsList.find(name) != functionsList.end();
}

void Visitor::insertFunction(const functionType& function) {
  functionsList.insert(std::make_pair(function.functionName, function));
}

bool Visitor::checkExistRecord(const std::string& name) {
  typeMap.find(name) != typeMap.end();
}

const recordType& Visitor::getRecord(const std::string& name) {
  return recordsList[typeMap.find(name)->second - Visitor::BUILT_IN_TYPE_COUNT];
}

const recordType& Visitor::getRecord(Type type) {
  return recordsList[type - Visitor::BUILT_IN_TYPE_COUNT];
}

void Visitor::insertRecord(const recordType& record) {
  typeMap.insert(
      {record.name, recordsList.size() + Visitor::BUILT_IN_TYPE_COUNT});
  recordsList.push_back(record);
}

Type Visitor::getType(const std::string& name) {
  auto builtInType = Visitor::BUILT_IN_TYPES_INDEX.find(name);
  if (builtInType != Visitor::BUILT_IN_TYPES_INDEX.end()) {
    return builtInType->second;
  } else if (checkExistRecord(name)) {
    return typeMap.find(name)->second;
  } else {
    return static_cast<Type>(-1);
  }
}

Type Visitor::getVariableType(const std::string& name) {
  if (currentFunction != nullptr &&
      currentFunction->localVariables.find(name) !=
          currentFunction->localVariables.end()) {
    return currentFunction->localVariables.find(name)->second;
  } else {
    if (globalVariables.find(name) != globalVariables.end()) {
      return globalVariables.find(name)->second;
    } else {
      return static_cast<Type>(-1);
    }
  }
}

}  // namespace ch2c