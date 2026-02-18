#include "rotational_cipher.h"


namespace rotational_cipher {

std::string rotate(std::string input, int key_num) {
    std::string res = "";
    
    for (char ch : input) {
        if (std::isalpha(ch)) {
            char base = std::isupper(ch) ? 'A' : 'a';
            
            char rotated = (char)((ch - base + key_num) % 26 + base);
            res += rotated;
        } else {
            res += ch;
        }
    }

    return res;
}

}  // namespace rotational_cipher
