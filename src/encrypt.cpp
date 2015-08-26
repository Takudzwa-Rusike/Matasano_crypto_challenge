#include "../include/util.hpp"
#include "../include/encrypt.hpp"

using std::string;

static void encrypt_letter(const char to_encrypt, char char_to_xor, string& ans, bool to_hex){
	int value = (int) to_encrypt;
	value = value ^ char_to_xor;
	if(to_hex){
		char second = from_decimal_to_hex( ( value % 16) );
		value/=16;
		char first = from_decimal_to_hex ( (value % 16) );
		ans += first;
		ans+=second;
	}else{
		ans+= value;
	}
}

string repeating_key_xor_encrypt(const std::string& to_encrypt, const std::string& key, bool to_hex){
	string ans = "";
	for(unsigned i = 0; i < to_encrypt.size();i++){
		int pos = ( i  % key.size() );
		char char_enc = key[pos];
		encrypt_letter(to_encrypt[i], char_enc, ans, to_hex);
	}   	

	return ans;
}

