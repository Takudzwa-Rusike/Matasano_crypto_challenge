#include "include/decode_encode.hpp"
#include "include/decrypt.hpp"
#include <fstream>

using std::cout;
using std::string;
using std::vector;
using std::fstream;

int main(){
	
	fstream filestream; 
	
	cout << "SET 1 \n";
	cout << "---------------------------------------\n";
	/*----------------------------------CHALLENGE 1---------------------------------------------*/
	cout << "CHALLENGE 1: \n";
	cout << "---------------------------------------\n";
	string challenge1_string ="49276d206b"
		"696c6c696e6720796f757220627261696e20"
		"6c696b65206120706f69736f6e6f7573206d"
		"757368726f6f6d" ;

	cout << "Hex String: \n" << challenge1_string << "\n"; 
	cout << "Base64 String: \n" << hex_to_base64(challenge1_string) << "\n";
	
	/*----------------------------------CHALLENGE 2---------------------------------------------*/
	
	cout << "---------------------------------------\n";	
	cout << "CHALLENGE 2: \n";
	cout << "---------------------------------------\n";	
	string ch2_str_1 ="1c0111001f010100061a024b53535009181c";
	string ch2_str_2 ="686974207468652062756c6c277320657965";

	cout << "Hex String: \n" << ch2_str_1 << "\n"; 
	cout << "String to xor with: \n" << ch2_str_2 << "\n"; 
	cout << "Result: \n" << xor_two_strings(ch2_str_1, ch2_str_2) <<"\n";
	
	/*----------------------------------CHALLENGE 3---------------------------------------------*/

	cout << "---------------------------------------\n";	
	cout << "CHALLENGE 3: \n";
	cout << "---------------------------------------\n";	
	vector<string> ch3_strs {"1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"};
	scorer ch3_result = single_byte_xor_decode(ch3_strs); 
	cout << ch3_result.key<< ": " << ch3_result.decoded_message << "\n";

	/*----------------------------------CHALLENGE 4---------------------------------------------*/

	cout << "---------------------------------------\n";	
	cout << "CHALLENGE 4: \n";
	cout << "---------------------------------------\n";	

	string ch4_key;
	vector<string> ch4_keys;
	
	filestream.open("files/4.txt", fstream::in);
	while( getline(filestream, ch4_key) )
		ch4_keys.push_back( ch4_key );
	
	scorer ch4_result = single_byte_xor_decode(ch4_keys); 
	cout << ch4_result.key<< ": " << ch4_result.decoded_message << "\n";

	filestream.close();


	return 0;
}
