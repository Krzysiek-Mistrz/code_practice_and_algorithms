#include "raindrops.h"


namespace raindrops {

std::string convert(int num) {
    std::string res = "";

    if (!(num % 3)) {
        res += "Pling";
    }
    if (!(num % 5)) {
        res += "Plang";
    }
    if (!(num % 7)) {
        res += "Plong";
    }
    if (res.empty()) {
        return std::to_string(num);
    }
    
    return res;
}

}  // namespace raindrops
