#include "../include/aes.hpp"
#include <openssl/aes.h>
#include "string.h"
#include <iostream>

using std::string;
using std::vector;

void aes_in_ecb( const unsigned char *to_decrypt, const unsigned char* key, unsigned char* ans, unsigned len){
	
	AES_KEY key_aes;
	AES_set_decrypt_key(key, 128, &key_aes);
	for(unsigned i = 0; i < len; i+=16)
		AES_decrypt( to_decrypt+i, ans+i, &key_aes);
	
	ans[len-1] = '\0';
}

static int ecb_score(const string& ecb_test){
	int score = 0;
	unsigned key_blocks = ecb_test.size()/16;
	for(unsigned i=0; i < key_blocks;i++){
		for(unsigned j = i+1; j < key_blocks;j++){
			for(unsigned k =0;k<16;k++){
				
				if(ecb_test[ (i*16)+k] == ecb_test[ (j*16)+k ]){
					score++;
				}

			}
		}
	}
	return score;
}

int detect_ecb( const vector<string>& strings ){
	int index = -1;
	int max = 0;
	for(unsigned i = 0; i < strings.size();i++){	
		int score = ecb_score(strings[i]);
		if(score > max){
			index = (int) i;
			max = score;
		}

	}
	return index;
}

