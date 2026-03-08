#include "polymorphism.h"


namespace animals {
    int main(int argc, char** argv) {
        std::vector<Animal*> zoo;
        zoo.push_back(new Dog());
        zoo[0]->sound();

        return EXIT_SUCCESS;
    }
}