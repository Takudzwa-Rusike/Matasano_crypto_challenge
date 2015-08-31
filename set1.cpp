#include "include/util.hpp"
#include "include/decrypt.hpp"
#include "include/encrypt.hpp"
#include "include/aes.hpp"
#include <fstream>

using std::cout;
using std::string;
using std::vector;
using std::fstream;

int main(){
	
	fstream filestream; 
	
	cout << "SET 1: BASICS \n";
	cout << "---------------------------------------\n";
	/*----------------------------------CHALLENGE 1---------------------------------------------*/
	cout << "CHALLENGE 1:CONVERT HEX TO BASE64 \n";
	cout << "---------------------------------------\n";
	string challenge1_string ="49276d206b"
		"696c6c696e6720796f757220627261696e20"
		"6c696b65206120706f69736f6e6f7573206d"
		"757368726f6f6d" ;

	cout << "Hex String: \n" << challenge1_string << "\n"; 
	cout << "Base64 String: \n" << hex_to_base64(challenge1_string) << "\n";
	
	/*----------------------------------CHALLENGE 2---------------------------------------------*/
	
	cout << "---------------------------------------\n";	
	cout << "CHALLENGE 2:FIXED XOR \n";
	cout << "---------------------------------------\n";	
	string ch2_str_1 ="1c0111001f010100061a024b53535009181c";
	string ch2_str_2 ="686974207468652062756c6c277320657965";

	cout << "Hex String: \n" << ch2_str_1 << "\n"; 
	cout << "String to xor with: \n" << ch2_str_2 << "\n"; 
	cout << "Result: \n" << xor_two_strings(ch2_str_1, ch2_str_2) <<"\n";
	
	/*----------------------------------CHALLENGE 3---------------------------------------------*/

	cout << "---------------------------------------\n";	
	cout << "CHALLENGE 3:SINGLE-BYTE XOR CIPHER \n";
	cout << "---------------------------------------\n";	
	vector<string> ch3_strs {"1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"};
	scorer ch3_result = single_byte_xor_decode(ch3_strs); 
	cout << ch3_result.key<< ": " << ch3_result.decoded_message << "\n";

	/*----------------------------------CHALLENGE 4---------------------------------------------*/

	cout << "---------------------------------------\n";	
	cout << "CHALLENGE 4:DETECT SINGLE-CHARACTER XOR \n";
	cout << "---------------------------------------\n";	

	string ch4_key;
	vector<string> ch4_keys;
	
	filestream.open("files/4.txt", fstream::in);
	while( getline(filestream, ch4_key) )
		ch4_keys.push_back( ch4_key );
	
	scorer ch4_result = single_byte_xor_decode(ch4_keys); 
	cout << ch4_result.key<< ": " << ch4_result.decoded_message << "\n";

	filestream.close();

/*----------------------------------CHALLENGE 5---------------------------------------------*/

	cout << "---------------------------------------\n";	
	cout << "CHALLENGE 5:IMPLEMENT REPEATING-KEY XOR \n";
	cout << "---------------------------------------\n";	

	string ch5_to_encrypt ="Burning 'em, if you ain't quick and nimble\n"
	"I go crazy when I hear a cymbal";	
	string ch5_key = "ICE";

	cout << "String to encrypt: \n" << ch5_to_encrypt << "\n";
	cout << "Repeating XOR key: \n" << ch5_key << "\n";
	cout << "Result: \n" << repeating_key_xor_encrypt(ch5_to_encrypt, ch5_key, true) << "\n";

/*----------------------------------CHALLENGE 6---------------------------------------------*/

	cout << "---------------------------------------\n";	
	cout << "CHALLENGE 6:BREAK REPEATING-KEY XOR \n";
	cout << "---------------------------------------\n";	
	
	string ch6_str = "",temp;	
	
	filestream.open("files/6.txt", fstream::in);
	while( getline(filestream, temp)){
		ch6_str +=temp;
	}
	
	cout << "Hamm distance between 'This is a test' and 'wokka wokka!!!' is "<< 
	ham_distance("this is a test", "wokka wokka!!!") << "\n";
	
	ch6_str = base64_to_hex( ch6_str );
	ch6_str = from_hex_to_dec(ch6_str);
	string ch6_ans = repeating_key_xor_decrypt(ch6_str);
	
	cout << "Decrypted string: \n" << ch6_ans << "\n";	

	filestream.close();

	/*----------------------------------CHALLENGE 7---------------------------------------------*/

	cout << "---------------------------------------\n";	
	cout << "CHALLENGE 7:AES IN ECB MODE \n";
	cout << "---------------------------------------\n";	

	string ch7_str;


	filestream.open("files/7.txt", fstream::in);
	while( getline(filestream, temp)){
		ch7_str +=temp;
	}

	ch7_str = base64_to_hex( ch7_str );
	ch7_str = from_hex_to_dec(ch7_str);


	unsigned char ch7_string[100000];
	for(unsigned i = 0; i < ch7_str.size();i++){
		ch7_string[i] = ch7_str[i];
	}
	ch7_string[ ch7_str.size() + 1] = '\0';

	filestream.close();
	
	const unsigned char ch7_key[] = {'Y','E','L','L','O','W',' ','S','U','B','M','A','R','I','N','E'};
	unsigned char ch7_ans[100000];
	aes_in_ecb(reinterpret_cast<const unsigned char* > (ch7_string), ch7_key, ch7_ans, ch7_str.size());
	ch7_ans[ch7_str.size() -1] = '\0';
	
	cout <<"Decrypted text: \n " << ch7_ans << "\n";
	
	/*----------------------------------CHALLENGE 8---------------------------------------------*/

	cout << "---------------------------------------\n";	
	cout << "CHALLENGE 8:DETECT AES IN ECB MODE \n";
	cout << "---------------------------------------\n";	
	
	vector<string> ch8_strings;
	filestream.open("files/8.txt", fstream::in);
	while( getline(filestream, temp)){
		ch8_strings.push_back(temp);
	}
	
	cout << "The ECB string is on line: " << (detect_ecb(ch8_strings) + 1) << "\n";
	
	filestream.close();
	
	return 0;
}

