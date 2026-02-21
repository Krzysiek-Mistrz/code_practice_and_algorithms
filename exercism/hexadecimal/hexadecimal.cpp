#include "hexadecimal.h"


namespace hexadecimal {

int convert(std::string hex) {
    int res{0};
    
    for (auto& ch : hex) {
        ch = std::tolower(ch);
    }

    for (int i{0}, j{static_cast<int>(hex.length()) - 1}; j >= 0; j--, i++) {
        if (hex.at(i) >= '0' and hex.at(i) <= '9')
            res += (hex.at(i) - '0') * std::pow(16, j);
        else if (hex.at(i) >= 'a' and hex.at(i) <= 'f')
            res += (hex.at(i) - 'a' + 10) * std::pow(16, j);
        else 
            return 0;
    }
    
    return res;
}

}  // namespace hexadecimal
