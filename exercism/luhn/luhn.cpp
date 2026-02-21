#include "luhn.h"


namespace luhn {

bool valid(std::string num) {
    std::stringstream ss{num};
    std::string t{""}, res{""};
    int sum{0}, count{1};

    while (getline(ss, t, ' '))
        res += t;

    if (res.length() < 2)
        return false;

    for (int i = res.length() - 1; i >= 0; i--) {
        if (not std::isdigit(res.at(i)))
            return false;
        
        if (not (count % 2)) {
            if (2 * (res.at(i) - '0') > 9)
                sum += 2 * (res.at(i) - '0') - 9;
            else
                sum += 2 * (res.at(i) - '0');
        } else {
            sum += res.at(i) - '0';
        }

        count += 1;
    }

    return not (sum % 10);
}

}  // namespace luhn
