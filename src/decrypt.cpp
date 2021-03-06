#include "../include/decrypt.hpp"
#include "../include/encrypt.hpp"
#include "../include/util.hpp"
#include <iostream>

using std::vector;
using std::string;

//taken from http://www.data-compression.com/english.html
std::map<char, double> letter_freq {
{'a', 0.0651738},
{'b', 0.0124248},
{'c', 0.0217339},
{'d', 0.0349835},
{'e', 0.1041442},
{'f', 0.0197881},
{'g', 0.0158610},
{'h', 0.0492888},
{'i', 0.0558094},
{'j', 0.0009033},
{'k', 0.0050529},
{'l', 0.0331490},
{'m', 0.0202124},
{'n', 0.0564513},
{'o', 0.0596302},
{'p', 0.0137645},
{'q', 0.0008606},
{'r', 0.0497563},
{'s', 0.0515760},
{'t', 0.0729357},
{'u', 0.0225134},
{'v', 0.0082903},
{'w', 0.0171272},
{'x', 0.0013692},
{'y', 0.0145984},
{'z', 0.0007836},
{' ', 0.1918182}
};

static int return_largest_score(const vector<scorer>& scores){
	double temp_max = 0;
	int index = -1;
	for(int i = 0; i < (int) scores.size();i++){
		if(temp_max < scores[i].score){
			temp_max = scores[i].score;
			index = i;
		}
	}
	return index;
}

static void calculate_scores(const string encoded_message, vector<scorer>& scores){

	for(int i = 0; i < 128;i++){
		string ans = "";
		scores[i].score = 0;
		scores[i].key = (char) i;
		for(int j = 0; j < (int) encoded_message.size() ; j+=2 ){

			int first = from_hex_to_decimal( encoded_message[j+1] );
			first += from_hex_to_decimal( encoded_message[j] ) << 4;
			int res = first ^ i;
			scores[i].score += letter_freq[ (char) tolower( res) ]  ;
			ans += char (res);
		}
		scores[i].decoded_message = ans;

	}

}

scorer single_byte_xor_decode(const vector<string>& encode_strs){
	
	vector<scorer> key_scores;
	for(unsigned i = 0; i < encode_strs.size();i++){
		vector<scorer> scores(128);
		calculate_scores(encode_strs[i], scores);
		int largest = return_largest_score(scores);
		key_scores.push_back( scores[largest] );
	}

	int largest = return_largest_score(key_scores);
	
	return key_scores[largest];

}

static void gather_strings(const string& decrypt_key, int key_size, vector<string>& key_blocks){
	
	for(unsigned i = 0; i< decrypt_key.size();i+=key_size){
		key_blocks.push_back( decrypt_key.substr(i,key_size ) );
	}

}

static void transpose_strings(const vector<string>& key_blocks, vector<string>& t_key_blocks){
	
	string temp = "";
	for(unsigned i = 0; i < key_blocks[0].size();i++){
		temp = "";
		for(unsigned j = 0; j < key_blocks.size()-1; j++){
			temp+=key_blocks[j][i];
		}
		t_key_blocks.push_back(temp);
	}

}

string repeating_key_xor_decrypt(string to_decrypt){
	string ans = "", key = "";
	vector<string> key_blocks, t_key_blocks;
	int key_size = get_key_size(to_decrypt);
	gather_strings(to_decrypt, key_size, key_blocks);
	transpose_strings( key_blocks, t_key_blocks);
	
	for(auto i: t_key_blocks){
		char a = most_freq_char(i) ^ ' ';
		key+= a;
	}
	
	return repeating_key_xor_encrypt(to_decrypt, key, false);
}	

