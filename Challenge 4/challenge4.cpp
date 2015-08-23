#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using std::cout; using std::cin;
using std::string;
using std::vector;
using std::fstream;
using std::sort;

struct scorer{
	int score;
	string decoded_message;
};

struct sorter_t{
	
	bool operator()(const scorer& a,const scorer& b){
		return a.score > b.score;
	}

} score_sorter;

int from_hex_to_decimal(char hex);

char from_decimal_to_hex(int dec);

scorer best_for_string(string char_string);

bool is_vowel_or_space( char letter);

int return_largest_score(const vector<scorer>& scores);

void calculate_scores(const string encoded_message, vector<scorer>& scores);

int main(){
	fstream fs;
	string key;
	vector<scorer> scores;
	
	fs.open("4.txt", fstream::in);
	
	while( getline(fs, key) )
		scores.push_back( best_for_string(key) );

	sort( scores.begin() , scores.end(), score_sorter);	

	for(int i = 0; i < scores.size();i++){
 	   cout << (char) i <<  ": score: " << scores[i].score << " message: " << scores[i].decoded_message << "\n";
	}	

	fs.close();
	return 0;
}

scorer best_for_string(string char_string){
	vector<scorer> scores(256);
	calculate_scores(char_string, scores);
	int pos = return_largest_score(scores);
	return scores[pos];
}


int return_largest_score(const vector<scorer>& scores){
	int temp_max = 0;
	int index = -1;

	for(int i = 0; i < scores.size();i++){
		if(temp_max < scores[i].score){
			temp_max = scores[i].score;
			index = i;
		}
	}
	return index;
}

void calculate_scores(const string encoded_message, vector<scorer>& scores){

	for(int i = 0; i <= 255;i++){
		string ans = "";
		scores[i].score = 0;

		for(int j = 0; j < encoded_message.size() ; j+=2 ){	
			int first = from_hex_to_decimal( encoded_message[j+1] );
			first += from_hex_to_decimal( encoded_message[j] ) << 4;
			int res = first ^ i;

			if( is_vowel_or_space( (char) res) ){
				scores[i].score++;
			}

			ans += char (res);
		}

		scores[i].decoded_message = ans;

	}

}

//counting vowels and spaces as my metric
bool is_vowel_or_space( char letter){
	return letter == 'a' || letter == 'e' || letter == 'i' ||
		letter == 'o' || letter == 'u' || letter == 'A' ||
		letter == 'E' || letter == 'I' || letter == 'O' ||
		letter == 'U' || letter == ' ';
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


