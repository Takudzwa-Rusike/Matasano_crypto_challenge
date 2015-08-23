#ifndef CHALLENGE6_H
#define CHALLENGE6_H

#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <unordered_map>

int from_64_to_decimal(char base64);

char from_decimal_to_hex(int dec);

std::string convert_substring(const std::string &test);

std::string convert_whole_string(const std::string &to_convert);

struct scorer{
		std::unordered_map<char, int> records;
		int score;
		char key;
		std::string decoded_message;
};

int from_hex_to_decimal(char hex);

char from_decimal_to_hex(int dec);

int return_largest_score(const std::vector<scorer>& scores);

void calculate_scores(const std::string encoded_message, std::vector<scorer>& scores);

void single_xor(const std::string& key );

#endif
