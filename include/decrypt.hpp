#ifndef DECRYPT
#define DECRYPT

#include <string>
#include <vector>
#include <map>

//taken from cryptograms.org
extern const std::map<char, double> letter_freq;

struct scorer{
	double score;
	std::string decoded_message;
};

std::string single_byte_xor_decode(const std::string& encode_str); 

#endif
