#include "functors_lambdas.h"


namespace project {

    int main(int argc, char** argv) {
        std::vector<int> v{1, 8, 4, 12, 5, 20};
        int greater_counter = std::count_if(v.begin(), v.end(), GreaterThan(10));
        int parity_counter = std::count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
        std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
        std::transform(v.begin(), v.end(), v.begin(), [](int x) { return x * 2; });

        std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    
        return EXIT_SUCCESS;
    }
}