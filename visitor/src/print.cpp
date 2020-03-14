#include <visitor.h>

namespace ch2c {

void Visitor::printVariables(const std::vector<variableDefinition>& variables) {
  for (int i = 0; i < variables.size(); i++) {
    outFile << getPrintName(variables[i].type) << " " << variables[i].name;
    if (!variables[i].initializer.empty()) {
      outFile << " = " << variables[i].initializer;
    }
    outFile << ';' << '\n';
  }
}

void Visitor::printFunctionSignature(const functionType& function,
                                     bool semicolon) {
  outFile << getPrintName(function.returnType) << ' '
          << function.functionPrintName << ' ';
  outFile << '(';
  for (int i = 0; i < function.parameterList.size(); i++) {
    if (i >= 1) {
      outFile << ", ";
    }
    outFile << getPrintName(function.parameterList[i].typeIndex) << ' '
            << function.parameterList[i].name;
  }
  outFile << ')';
  if (semicolon) {
    outFile << ";\n";
  }
}

void Visitor::printMethodSignature(const recordType& record,
                                   const functionType& function) {
  outFile << getPrintName(function.returnType) << ' '
          << function.functionPrintName << ' ';
  outFile << '(';
  outFile << record.name << " *this";
  for (int i = 0; i < function.parameterList.size(); i++) {
    outFile << ", ";
    outFile << getPrintName(function.parameterList[i].typeIndex) << ' '
            << function.parameterList[i].name;
  }
  outFile << ')';
}

void Visitor::printRecord(const recordType& record) {
  outFile << "typedef struct " << record.name << " {\n";
  for (auto i = record.members.begin(); i != record.members.end(); i++) {
    outFile << getPrintName(i->second.typeIndex) << " " << i->first << ";\n";
  }
  outFile << "} " << record.name << ";\n\n";
}

void Visitor::printExpression(const std::string& expression) {
  outFile << expression << ';' << '\n';
}

void Visitor::printHeader() {
  outFile << "#include<stdint.h>" << '\n';
  outFile << "#define " + Visitor::BUILT_IN_TYPES_PRINT[1] + " unsigned char"
          << '\n';
  outFile << "#define " + Visitor::BUILT_IN_TYPES_PRINT[2] + " int8_t" << '\n';
  outFile << "#define " + Visitor::BUILT_IN_TYPES_PRINT[3] + " uint8_t" << '\n';
  outFile << "#define " + Visitor::BUILT_IN_TYPES_PRINT[4] + " int16_t" << '\n';
  outFile << "#define " + Visitor::BUILT_IN_TYPES_PRINT[5] + " uint16_t"
          << '\n';
  outFile << "#define " + Visitor::BUILT_IN_TYPES_PRINT[6] + " int32_t" << '\n';
  outFile << "#define " + Visitor::BUILT_IN_TYPES_PRINT[7] + " uint32_t"
          << '\n';
  outFile << "#define " + Visitor::BUILT_IN_TYPES_PRINT[8] + " int64_t" << '\n';
  outFile << "#define " + Visitor::BUILT_IN_TYPES_PRINT[9] + " uint64_t"
          << '\n';
  outFile << "#define " + Visitor::BUILT_IN_TYPES_PRINT[10] + " float" << '\n';
  outFile << "#define " + Visitor::BUILT_IN_TYPES_PRINT[11] + " double" << '\n';
  outFile << "#define " + Visitor::BUILT_IN_TYPES_PRINT[12] + " char*" << '\n';
  outFile << "#define " + Visitor::TRUE_NAME + "1" << '\n';
  outFile << "#define " + Visitor::FALSE_NAME + "0" << '\n';
  outFile << "\n\n";
}

}  // namespace ch2c