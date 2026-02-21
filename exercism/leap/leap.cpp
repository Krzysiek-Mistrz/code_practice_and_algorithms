#include "leap.h"

namespace leap {
    
bool is_leap_year(int num) {
    if (!(num % 4) and (num % 100)) {
        return true;
    } else if (!(num % 4) and !(num % 100) and !(num % 400)) {
        return true;
    } else {
        return false;
    }
}

}  // namespace leap
