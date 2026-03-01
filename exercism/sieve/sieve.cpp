#include "sieve.h"


namespace sieve {

std::vector<int> primes(int limit) {
    if (limit < 2)
        return {};
    
    std::vector<bool> is_prime_flag(limit + 1, true);
    is_prime_flag[0] = is_prime_flag[1] = false;

    for (int p{2}; p * p <= limit; p++) {
        if (is_prime_flag[p]) {
            for (int i{p * p}; i <= limit; i += p) {
                is_prime_flag[i] = false;
            }
        }
    }

    std::vector<int> result;

    for (int p{2}; p <= limit; p++) {
        if (is_prime_flag[p])
            result.emplace_back(p);
    }

    return result;
}

}  // namespace sieve
