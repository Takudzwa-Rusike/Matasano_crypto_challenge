#ifndef DECRYPT
#define DECRYPT

#include <string>
#include <vector>
#include <map>

//taken from cryptograms.org
extern std::map<char, double> letter_freq;

struct scorer{
	double score;
	char key;
	std::string decoded_message;
};

scorer single_byte_xor_decode(const std::vector<std::string>& encode_str);

#endif
