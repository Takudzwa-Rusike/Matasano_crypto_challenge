#ifndef AES_HPP
#define AES_HPP

#include <string>
#include <vector>

void aes_in_ecb( const unsigned char *to_decrypt, const unsigned char* key, unsigned char* ans, unsigned len);

int detect_ecb( const std::vector<std::string>& strings );

#endif
