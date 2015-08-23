//repeated key xor encryption
//

#include <iostream>
#include <string>

using std::cout; using std::cin;
using std::string;

int from_hex_to_decimal(char hex);

char from_decimal_to_hex(int dec);

void encrypt_letter(const char to_encrypt, char char_to_xor, string& ans);

int main(){
	
	string test, ans = "";
	string key = "ICE";
	cout << "Please input the string to be encrypted\n";
	getline(cin, test);
	
	for(int i = 0; i < test.size();i++){
		int pos = ( i  % 3 );
		char to_encrypt = key[pos];
		encrypt_letter(test[i], to_encrypt, ans);
	}
	
	cout << ans<< "\n";

	return 0;
}

void encrypt_letter(const char to_encrypt, char char_to_xor, string& ans){

	int value = (int) to_encrypt;
	value = value ^ char_to_xor;
	char second = from_decimal_to_hex( ( value % 16) );
	value/=16;
	char first = from_decimal_to_hex ( (value % 16) );
	ans += first;
	ans+=second;

}

//taken from challenge page
int from_hex_to_decimal(char hex){
	
	if('0' <= hex && hex <='9' )
		return hex - '0';

	if( hex >= 'A' && hex <= 'Z')
		return hex - 'A' + 10;

	return hex - 'a' + 10;
}

char from_decimal_to_hex(int dec){
	
	if(dec >= 0 && dec <= 9 )
		return '0' + dec;

	else if( dec >= 10 && dec <= 15)
		return 'a' - 10 + dec;

	return '\0';
}


