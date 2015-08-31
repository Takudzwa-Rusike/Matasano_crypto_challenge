#include "../include/block_cipher.hpp"

using std::string;

void pkcs_padding(const int& block_size, string& plaintext){
	int bytes_to_pad = block_size - (int) plaintext.size();
	for(int i = 0; i < bytes_to_pad;i++){
		plaintext += (char) 4;
	}
}

void cbc_decryption(string& to_decrypt, string& IV){
	unsigned index = 0;

	while( index < IV.size() ){
	}	

}

