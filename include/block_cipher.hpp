#ifndef BLOCK_CIPHER_HPP
#define BLOCK_CIPHER_HPP

#include <string>

void pkcs_padding(const int& block_size, std::string& plaintext);

void cbc_decryption(std::string& to_decrypt, std::string& IV);

#endif
