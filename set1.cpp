#include "include/decode_encode.hpp"
using std::cout;
using std::string;

int main(){
	cout << "SET 1 \n";
	cout << "CHALLENGE 1: \n";
	string challenge1_string ="49276d206b"
		"696c6c696e6720796f757220627261696e20"
		"6c696b65206120706f69736f6e6f7573206d"
		"757368726f6f6d" ;

	cout << "Hex String: \n" << challenge1_string << "\n"; 
	cout << "Base64 String: \n" << convert_string_from_hex_to_base64(challenge1_string) << "\n";

	return 0;
}
