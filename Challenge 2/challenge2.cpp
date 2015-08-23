#include <iostream>
#include <string>

using std::cout; using std::cin;
using std::string;

int from_hex_to_decimal(char hex);

char from_decimal_to_hex(int dec);

int main(){
	
	string test, test2, ans = "";

	cout << "Please input the hexidecimal string\n";
	cin >> test;
	cout << "Please input the hexidecimal string to be xored with\n";
	cin >> test2;
	
	if(test.size() != test2.size()){
		cout << "The two strings aren't the same size\n";
		return 1;
	}

	for(int i = 0; i < test.size() ; i++ ){	
		int first = from_hex_to_decimal( test[i] );
		int second = from_hex_to_decimal( test2[i] );
		int res = first ^ second;
		ans += from_decimal_to_hex(res);
	}
	cout << "\n";
	cout << ans <<"\n";

	return 0;
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


