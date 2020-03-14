#include <string>

namespace ch2c {

std::string numLiteral(std::string s) {
  const char* data = s.c_str();
  int shift = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '_') {
      shift++;
    } else {
      s[i - shift] = s[i];
    }
  }
  s.resize(s.length() - shift);
  return s;
}

}  // namespace ch2c