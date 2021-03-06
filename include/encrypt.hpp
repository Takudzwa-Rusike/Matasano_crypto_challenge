#ifndef ENCRYPT_HPP
#define ENCRYPT_HPP

#include <string>

std::string repeating_key_xor_encrypt(const std::string& to_encrypt, const std::string& key, bool to_hex);

#endif
