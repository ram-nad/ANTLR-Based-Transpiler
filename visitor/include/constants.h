#include <visitor.h>

#ifndef CH_CONSTANT_H
#define CH_CONSTANT_H CH_CONSTANT_H

namespace ch2c {

std::size_t Visitor::BUILT_IN_TYPE_COUNT = 13;

std::vector<std::string> Visitor::BUILT_IN_TYPES_PRINT = {
    "void",      "ch_bool",   "ch_int8",   "ch_uint8", "ch_int16",
    "ch_uint16", "ch_int32",  "ch_uint32", "ch_int64", "ch_uint64",
    "ch_real32", "ch_real64", "ch_string"};

std::vector<std::string> Visitor::BUILT_IN_TYPES = {
    "void",     "bool",     "int(8)",   "uint(8)", "int(16)",
    "uint(16)", "int(32)",  "uint(32)", "int(64)", "uint(64)",
    "real(32)", "real(64)", "string"};

std::map<std::string, Type> Visitor::BUILT_IN_TYPES_INDEX = {
    {"void", 0},      {"bool", 1},      {"int(8)", 2},  {"uint(8)", 3},
    {"int(16)", 4},   {"uint(16)", 5},  {"int(32)", 6}, {"uint(32)", 7},
    {"int(64)", 8},   {"uint(64)", 9},  {"int", 8},     {"uint", 9},
    {"real(32)", 10}, {"real(64)", 11}, {"real", 11},   {"string", 12}};

std::string Visitor::TRUE_NAME = "ch_true_t";
std::string Visitor::FALSE_NAME = "ch_false_t";

Visitor::visitorError Visitor::Error;

}  // namespace ch2c

#endif