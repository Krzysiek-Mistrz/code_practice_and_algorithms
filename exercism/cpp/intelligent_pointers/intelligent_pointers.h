#include <iostream>
#include <memory>
#include <vector>
#include <typeinfo>
#include <utility>


namespace robots {

class Robot {
public:
    inline void bip_bop() { std::cout << "bip bop!"; }
};

}