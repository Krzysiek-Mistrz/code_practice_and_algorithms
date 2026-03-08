#include "armstrong_numbers.h"


namespace armstrong_numbers {

bool is_armstrong_number(int num) {
    std::string num_string{std::to_string(num)};
    int len{static_cast<int>(num_string.length())};
    int sum{0};

    for (const auto& ch : num_string) {
        sum += std::pow(ch - '0', len);
    }
    
    return sum == num;
}

}  // namespace armstrong_numbers
