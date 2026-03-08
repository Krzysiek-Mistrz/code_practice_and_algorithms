#include "rule_of_five.h"


namespace warehouses {
    int main(int argc, char** argv) {
        Warehouse w1("warehouse 1");
        Warehouse w2 = w1;
        w2.set_data("warehouse 2");

        std::cout << "warehouse 1 name: " << w1.get_data() << std::endl;
        std::cout << "warehouse 2 name: " << w2.get_data() << std::endl;

        return EXIT_SUCCESS;
    }
}