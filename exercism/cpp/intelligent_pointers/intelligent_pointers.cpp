#include "intelligent_pointers.h"


namespace robots {

    int main(int argc, char** argv) {
        std::unique_ptr<Robot> r1 = std::make_unique<Robot>();
        auto r2 = std::move(r1);
        r1->bip_bop();

        std::shared_ptr<Robot> s1 = std::make_shared<Robot>();
        auto s2 = s1;

        std::cout << "counter: " << s1.use_count() << std::endl;
        std::cout << "type of object rtti: " << typeid(*s1).name() << '\n';

        return EXIT_SUCCESS;
    }
   
}