//Let Keysize by the guessed length
//
//compute the hamming distance between two strings
//
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "challenge6.h"


using std::cout; using std::cin;
using std::string;
using std::pow;
using std::stack;
using std::fstream;
using std::vector;

double ham_distance(const string& a, const string& b);
int get_key_size(const string& decryp_key);
string current_string(const string& decryp_key);
void gather_strings(const string& decrypt_key, int key_size, vector<string>& key_blocks);
void transpose_strings(const vector<string>& key_blocks, vector<string>& t_key_blocks);
string current_string(const string& decryp_key);

int main(){

	fstream fs;
	string encrypted_string, decrypted_string, temp;
	vector<string> key_blocks, t_key_blocks;

	fs.open("6.txt", fstream::in);

	while( getline(fs, temp)){
		encrypted_string +=temp;
	};
	//cout << ham_distance("this is a test", "wokka wokka!!!") << "\n";

	decrypted_string = convert_whole_string(encrypted_string);
	//cout << (int) decrypted_string[0] <<"\n";

	string dec_string = current_string(decrypted_string);

	int key_size = get_key_size( dec_string );

	cout << key_size << "\n";
  gather_strings(dec_string, key_size, key_blocks);
	transpose_strings(key_blocks, t_key_blocks);
	single_xor( t_key_blocks[0]);
	return 0;
}

double ham_distance(const string& a, const string& b){
	//assuming a and b both have the same length

	//if( a.size() != b.size() )
	//	exit(0);

	double dist = 0;
	for(int i = 0; i < a.size();i++){
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

string current_string(const string& decryp_key){
	string new_string = "";

	for(int i = 0; i < decryp_key.size();i+=2){

		int new_char = from_hex_to_decimal( decryp_key[i] ) << 4;
		new_char += from_hex_to_decimal( decryp_key[i+1]) ;
		new_string += (char) new_char;
	}
	return new_string;

}

int get_key_size(const string& decryp_key){
	vector<double> results(61);
	double max = 1000000000;
	int index = -1;

	for(int i = 2; i < 40;i++){

			int num_blocks = decryp_key.size() / i;

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

void gather_strings(const string& decrypt_key, int key_size, vector<string>& key_blocks){

	for(int i = 0; i< decrypt_key.size();i+=key_size){
		key_blocks.push_back( decrypt_key.substr(i,key_size ) );
	}
}

void transpose_strings(const vector<string>& key_blocks, vector<string>& t_key_blocks){
	string temp = "";
	for(int i = 0; i < key_blocks[0].size();i++){
		temp = "";
		for(int j = 0; j < key_blocks.size()-1; j++){
			temp+=key_blocks[j][i];
		}
		t_key_blocks.push_back(temp);
	}

}
