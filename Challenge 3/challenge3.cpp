#include <iostream>
#include <string>
#include <vector>

using std::cout; using std::cin;
using std::string;
using std::vector;

struct scorer{
	int score;
	string decoded_message;
};

int from_hex_to_decimal(char hex);

char from_decimal_to_hex(int dec);

int return_largest_score(const vector<scorer>& scores);

void calculate_scores(const string encoded_message, vector<scorer>& scores);

int main(){
	
	string test, ans = "";
	char test_char;
	vector<scorer> scores(256);
	cout << "Please input the hexidecimal string\n";
	cin >> test;

	calculate_scores(test, scores);
	
	int pos = return_largest_score(scores);

	cout << (char) pos <<  ": score: " << scores[pos].score << " message: " << scores[pos].decoded_message << "\n";  
	
	

	return 0;
}


int return_largest_score(const vector<double>& scores){
	int temp_max = 0;
	int index = -1;

	for(int i = 0; i < (int) scores.size();i++){
		if(temp_max < scores[i]){
			temp_max = scores[i];
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

