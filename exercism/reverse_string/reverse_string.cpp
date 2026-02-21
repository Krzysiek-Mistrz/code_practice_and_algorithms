#include "reverse_string.h"


namespace reverse_string {

std::string reverse_string(std::string str) {
    std::string res = "";
    
    for (int i = str.length() - 1; i >= 0; i--) {
        res += str.at(i);
    }
    
    return res;
}

}  // namespace reverse_string
