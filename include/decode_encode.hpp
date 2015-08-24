#ifndef DECODE_ENCODE
#define DECODE_ENCODE

#include <iostream>
#include <string>
#include <cmath>
#include <stack>

char from_decimal_to_base64( int dec);

char from_decimal_to_hex(int dec);

int from_hex_to_decimal(char hex);

std::string hex_to_base64(const std::string &to);

std::string xor_two_strings(const std::string& a, const std::string& b);

#endif
