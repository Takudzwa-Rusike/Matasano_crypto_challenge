#include "../include/decode_encode.hpp"

using std::string;
using std::pow;
using std::stack;
using std::cout;

static string convert_string(const string &test){
	stack<int> s;
	string result_s = "";
	int result_i = 0;
	for(int i = test.size()-1; i >=0;i--){
		result_i += from_hex_to_decimal(test[i])*pow( 16 , (test.size()-i-1));
	}

	while(result_i >0){
		int num = result_i %64;
		result_i/= 64;
		s.push( num );
	}

	while( !s.empty() ){
		result_s+= from_decimal_to_base64(s.top());
		s.pop();
	}

	return result_s;
}

string hex_to_base64(const string &to){

	string ans = "";

	for(int i = 0; i < (int) to.size() ; i+=3 ){
		int char_left =  to.size() - (i + 1);

		if(  char_left >= 3){
			ans += convert_string( to.substr( i ,3 ) );
		}else{

			ans += convert_string ( to.substr( i , (char_left+1) ) );
		}

	}

	return ans;
}

//taken from challenge page
int from_hex_to_decimal(char hex){

	if('0' <= hex && hex <='9' )
		return hex - '0';

	if( hex >= 'A' && hex <= 'Z')
		return hex - 'A' + 10;

	return hex - 'a' + 10;
}

char from_decimal_to_base64( int dec){

	if(dec>=0 && dec<=25)
		return (char) 'A' + dec;

	else if(dec>=26 && dec <= 51)
		return (char) 'a' + dec - 26;
	else if(dec >=52 && dec<= 61)
		return (char) '0' + dec - 52;
	else if(dec == 62)
		return '+';
	else if(dec == 63)
		return '/';

	return '\0';
}

char from_decimal_to_hex(int dec){

	if(dec >= 0 && dec <= 9 ) 
		return '0' + dec;

	else if( dec >= 10 && dec <= 15) 
		return 'a' - 10 + dec;

	return '\0';
}

string xor_two_strings(const string& a, const string& b){
	string ans;
	if(a.size() != b.size()){
		cout << "The two strings aren't the same size\n";
		return "";
	}   

	for(int i = 0; i < (int) a.size() ; i++ ){  
		int first = from_hex_to_decimal( a[i] );
		int second = from_hex_to_decimal( b[i] );
		int res = first ^ second;
		ans += from_decimal_to_hex(res);
	}   
	return ans;


}

