#ifndef UTIL
#define UTIL

#include <iostream>
#include <string>
#include <cmath>
#include <stack>

int from_base64_to_decimal(char base64);

std::string base64_to_hex(const std::string &to_convert);

char from_decimal_to_base64( int dec);

char from_decimal_to_hex(int dec);

int from_hex_to_decimal(char hex);

std::string hex_to_base64(const std::string &to);

std::string from_hex_to_dec(const std::string& to);

std::string xor_two_strings(const std::string& a, const std::string& b);

double ham_distance(const std::string& a, const std::string& b);

int get_key_size(const std::string& decryp_key);

#endif
