#include <string>

#ifndef CH_ERROR_H
#define CH_ERROR_H CH_ERROR_H

namespace ch2c {

std::string SimpleError(const std::string& error) { return std::string(error); }

std::string SimpleError(const std::string& type, const std::string& error) {
  return type + ": " + error;
}

template <typename... data>
std::string DetailedError(const std::string& type, std::size_t line,
                          std::size_t column, const char* format,
                          data... Data) {
  char fullError[200];
  std::snprintf(fullError, 199, format, Data...);
  return type + " at Line " + std::to_string(line) + " Column " +
         std::to_string(column) + ": " + std::string(fullError);
}

}  // namespace ch2c

#endif