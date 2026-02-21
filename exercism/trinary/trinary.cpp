#include "trinary.h"


namespace trinary {

int to_decimal(std::string trinary_num) {
    int res{0};

    for (int i{static_cast<int>(trinary_num.length()) - 1}, j{0}; i >= 0; i--, j++) {
        if (trinary_num.at(j) != '0' and trinary_num.at(j) != '1' and trinary_num.at(j) != '2')
            return 0;
        else
            res += (trinary_num.at(j) - '0') * std::pow(3, i);
    }

    return res;
}

}  // namespace trinary
