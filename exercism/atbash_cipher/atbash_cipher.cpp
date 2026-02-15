#include "atbash_cipher.h"
#include <cctype>


namespace atbash_cipher {

std::string encode(const std::string& input) {
    std::string res{""};
    int count{0};

    for (char c : input) {
        if (std::isalnum(c)) {
            if (count > 0 and count % 5 == 0) {
                res += ' ';
            }

            if (std::isalpha(c)) {
                res += (char)('a' + ('z' - std::tolower(c)));
            } else {
                res += c;
            }

            count++;
        }
    }

    return res;
}

std::string decode(const std::string& input) {
    std::string res{""};

    for (char c : input) {
        if (std::isalnum(c)) {
            if (std::isalpha(c)) {
                res += (char)('a' + ('z' - std::tolower(c)));
            } else {
                res += c;
            }
        }
    }

    return res;
}

}  // namespace atbash_cipher
