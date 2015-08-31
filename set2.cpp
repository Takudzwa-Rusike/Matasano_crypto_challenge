#include "include/block_cipher.hpp"

#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::fstream;
using std::string;

int main(){

	fstream filestream; 

	cout << "SET 2: BLOCK CRYPTOGRAPHY \n";
	/*----------------------------------CHALLENGE 9---------------------------------------------*/
	cout << "---------------------------------------\n";
	cout << "CHALLENGE 9:IMPLEMENT PKCS#7 PADDING\n";
	cout << "---------------------------------------\n";

	string ch9_string = "YELLOW SUBMARINE";
	cout << "The string before padding is " << ch9_string << " and has " << ch9_string.size() << " bytes\n";
	pkcs_padding(20, ch9_string);
	cout << "The string after padding is " << ch9_string << " and has " << ch9_string.size() << " bytes\n";

	cout << "---------------------------------------\n";
	cout << "CHALLENGE 10:IMPLEMENT CBC MODE\n";
	cout << "---------------------------------------\n";

	string ch10_str,temp;
	filestream.open("files/10.txt", fstream::in);
	
	while( getline(filestream, temp)){
		ch10_str +=temp;
	}
	
	string ch10_initialIV = "\0\0\0";
	cout << ch10_initialIV.size() << "\n";
	//cbc_decryption(ch10_str, ch10_initialIV);

	return 0;
}

