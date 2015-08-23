#include "challenge6.h"

using std::string;
using std::stack;
using std::vector;
using std::cout;
using std::unordered_map;

//------------------------------------------CHALLENGE 1 CODE-----------------------------------------------------------------

int from_64_to_decimal(char base64){
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

char from_decimal_to_hex(int dec){
	if(dec >= 0 && dec < 10)
		return (char) ('0' + dec);
	if(dec >= 10 && dec < 16)
		return (char) ('a' + dec - 10);
	return '\0';
}

string convert_substring(const string &test){
	stack<int> s;
	string result_s = "";
	int result_i = 0;
	for(int i = test.size()-1; i >=0;i--){
		result_i += from_64_to_decimal(test[i])*pow( 64 , (test.size()-i-1));
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

string convert_whole_string(const std::string &to_convert){
	string ans = "";
	for(int i = 0; i < to_convert.size() ; i+=2 ){
		int char_left =  to_convert.size() - (i + 1);

		if(  char_left >= 2){
			ans += convert_substring( to_convert.substr( i ,2 ) );
		}else{

			ans += convert_substring ( to_convert.substr( i , (char_left+1) ) );
		}

	}

	return ans;
}

//------------------------------------------CHALLENGE 3 CODE---------------------------------------------------

void single_xor(const string& key ){
	vector<scorer> scores(256);
	calculate_scores(key, scores);

	char pos = return_largest_score(scores);

//	cout << (char) pos <<  ": score: " << scores[pos].score << " message: " << scores[pos].decoded_message << "\n";

}

int return_largest_score(const vector<scorer>& scores){
	int temp_max = 0;
	int index = '\0';

	for(int i = 0; i < scores.size();i++){
		if(temp_max < scores[i].score){
			temp_max = scores[i].score;
			index = i;
		}
	}
	return index;
}

static void  return_score( scorer& score){
	int temp_max = 0;
	char index = '\0';

	for(auto i : score.records){
		if(temp_max < i.second){
			temp_max = i.second;
			index = i.first;
		}
	}
	score.score = temp_max;
	score.key = index;
}

void calculate_scores(const string encoded_message, vector<scorer>& scores){

	for(int i = 0; i <= 255;i++){
		string ans = "";

		for(int j = 0; j < encoded_message.size() ; j++ ){
			for(int k = j+1;k < encoded_message.size();k++){

				int first = (int) encoded_message[j] ;
				int second = (int) encoded_message[k];
				int res = first ^ i;
				int res2 = second ^ i;

					if(res == res2 ){
						//cout << res << " " << res2 << "\n";
						scores[i].score++;
					}

				}

			//ans += char (res);
		}

		scores[i].decoded_message = ans;
		//return_score( scores[i]);
		cout << (char) i <<  ": score: " << scores[i].score << " Key: "<< scores[i].key <<"\n";
	}

}

int from_hex_to_decimal(char hex){

	if('0' <= hex && hex <='9' )
		return hex - '0';

	if( hex >= 'A' && hex <= 'Z')
		return hex - 'A' + 10;

	return hex - 'a' + 10;
}
