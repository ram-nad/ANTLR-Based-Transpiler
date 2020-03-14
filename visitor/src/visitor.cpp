#include <antlr4-runtime/antlr4-runtime.h>
#include <constants.h>
#include <grammar/BasicLexer.h>
#include <grammar/BasicParser.h>
#include <visitor.h>

#include <iostream>

using namespace antlr4;
using namespace ch2c;

int main(int argc, const char* argv[]) {
  std::ifstream stream;
  stream.open(argv[1]);

  ANTLRInputStream input(stream);
  BasicLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  BasicParser parser(&tokens);
  BasicParser::FileContext* tree = parser.file();
  Visitor visitor;
  visitor.visitFile(tree);
  std::ofstream out;
  out.open("output.c");
  out << visitor.outFile.str();
  if (visitor.Error.isError) {
    for (int i = 0; i < visitor.Error.Errors.size(); i++) {
      std::cout << visitor.Error.Errors[i] << std::endl;
    }
  }
  out.close();
  stream.close();
  return 0;
}