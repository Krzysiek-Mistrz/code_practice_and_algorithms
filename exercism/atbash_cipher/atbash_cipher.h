#pragma once

#include <string>
#include <cctype>


namespace atbash_cipher {

std::string encode(const std::string& input);

std::string decode(const std::string& input);

}  // namespace atbash_cipher
