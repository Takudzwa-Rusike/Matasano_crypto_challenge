#include "../include/decrypt.hpp"
#include "../include/decode_encode.hpp"

using std::vector;
using std::string;

std::map<char, double> letter_freq {
	{'a', 0.08167},	
	{'b', 0.01492},	
	{'c', 0.02782},	
	{'d', 0.04253},	
	{'e', 0.12702},	
	{'f', 0.02228},	
	{'g', 0.02015},	
	{'h', 0.06094},	
	{'i', 0.06966},	
	{'j', 0.00153},	
	{'k', 0.00772},	
	{'l', 0.04025},	
	{'m', 0.02406},	
	{'n', 0.06749},	
	{'o', 0.07507},	
	{'p', 0.01929},	
	{'q', 0.00095},	
	{'r', 0.05987},	
	{'s', 0.06327},	
	{'t', 0.09056},	
	{'u', 0.02758},	
	{'v', 0.00978},	
	{'w', 0.02360},	
	{'x', 0.00150},	
	{'y', 0.01974},	
	{'z', 0.00074}	
};


static int return_largest_score(const vector<scorer>& scores){
	int temp_max = 0;
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

	for(int i = 0; i <= 255;i++){
		string ans = "";
		scores[i].score = 0;

		for(int j = 0; j < (int) encoded_message.size() ; j+=2 ){

			int first = from_hex_to_decimal( encoded_message[j+1] );
			first += from_hex_to_decimal( encoded_message[j] ) << 4;
			int res = first ^ i;
			scores[i].score += letter_freq[ (char) res ]  ;
			ans += char (res);
		
		}

		scores[i].decoded_message = ans;

	}

}

std::string single_byte_xor_decode(const std::string& encode_str){
	
	string ans = "";
	vector<scorer> scores(256);
	calculate_scores(encode_str, scores);
	int largest = return_largest_score(scores);
	return scores[largest].decoded_message;

}


