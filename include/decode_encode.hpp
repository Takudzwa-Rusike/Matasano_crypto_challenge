#ifndef DECODE_ENCODE
#define DECODE_ENCODE

#include <iostream>
#include <string>
#include <cmath>
#include <stack>

char from_decimal_to_base64( int dec);

int from_hex_to_decimal(char hex);

std::string convert_string_from_hex_to_base64(const std::string &to);

#endif
