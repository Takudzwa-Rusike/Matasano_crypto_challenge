#include "../include/util.hpp"
#include <stdlib.h>
#include <vector>
using std::string;
using std::pow;
using std::stack;
using std::cout;
using std::vector;

static string substr_from_base64_to_hex(const string &test){
	stack<int> s;
	string result_s = ""; 
	int result_i = 0;
	for(int i = test.size()-1; i >=0;i--){
		result_i += from_base64_to_decimal(test[i])*pow( 64 , (test.size()-i-1));
	}   

	for(int i = 0; i < 3;i++){
		int num = result_i % 16; 
		result_i/= 16; 
		s.push( num );
	}   

	while( !s.empty() ){
		result_s+= from_decimal_to_hex(s.top());
		s.pop();
	}   

	return result_s;
}

static string substr_from_hex_to_base64(const string &test){
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

string from_hex_to_dec(const string& to){
	string new_string = "";

	for(unsigned i = 0; i < to.size();i+=2){

		int new_char = from_hex_to_decimal( to[i] ) << 4;
		new_char += from_hex_to_decimal( to[i+1]) ;
		new_string += (char) new_char;
	}

	return new_string;

}

string hex_to_base64(const string &to){

	string ans = "";

	for(int i = 0; i < (int) to.size() ; i+=3 ){
		int char_left =  to.size() - (i + 1);

		if(  char_left >= 3){
			ans += substr_from_hex_to_base64( to.substr( i ,3 ) );
		}else{

			ans += substr_from_hex_to_base64( to.substr( i , (char_left+1) ) );
		}

	}

	return ans;
}

string base64_to_hex(const std::string &to_convert){
	string ans = ""; 
	for(int i = 0; i < (int) to_convert.size() ; i+=2 ){
		int char_left =  to_convert.size() - (i + 1); 

		if(  char_left >= 2){ 
			ans += substr_from_base64_to_hex( to_convert.substr( i ,2 ) );
		}else{

			ans += substr_from_base64_to_hex( to_convert.substr( i , (char_left+1) ) );
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

int from_base64_to_decimal(char base64){
	int value = (int) base64;
	if( value >= (int) 'A' && value <= (int) 'Z' )
		return value - (int) 'A';
	else if( value >= (int) 'a' && value <= (int) 'z' )
		return value - (int) 'a' + 26; 
	else if( value >= (int) '0' && value <= (int) '9' )
		return value - (int) '0' + 52; 
	else if( value == (int) '+' )
		return 62; 
	else if( value == (int) '/' )
		return 63; 
	return -1; 
}

double ham_distance(const string& a, const string& b){
	//assuming a and b both have the same length
	//
	
	if( a.size() != b.size() )
	  exit(0);

	double dist = 0;
	for(unsigned i = 0; i < a.size();i++){
		int first = (int) a[i] ;
		int second = (int) b[i] ;

		for(int i = 0; i < 8;i++){
			int a_bit = first%2;
			int b_bit = second%2;
			first/=2;
			second/=2;
			if(a_bit != b_bit)
				dist++;
		}
	}
	return dist;
}

int get_key_size(const string& decryp_key){
	vector<double> results(41);
	double max = 1000000000;
	int index = -1; 

	for(int i = 2; i < 40;i++){

		for(int j = 0; j < 12;j++){
			for(int k = j+1;k < 12;k++){
				results[i] += ham_distance( decryp_key.substr( (j*i),i ), decryp_key.substr( (k*i) ,i) ) / ( (double) i) ;
			}   
		}   

	}   

	for(int i = 2; i< 40;i++){
		if(max > results[i]){
			max = results[i];
			index = i;
		}   
	}   

	return index;
}

static int return_largest(const vector<int>& p){
	double temp_max = -1;
	int index = -1; 
	for(int i = 0; i < (int) p.size();i++){
		if(temp_max < p[i]){
			temp_max = p[i];
			index = i;
		}   
	}   
	return index;
}


char most_freq_char(const string& to_see){
	vector<int> chars(256);
	for(unsigned i = 0;i <  to_see.size();i++){
		chars[ (int) to_see[i] ]++;
	}

	return (char) return_largest(chars);
	
}

