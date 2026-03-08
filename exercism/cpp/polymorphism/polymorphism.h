#include <iostream>
#include <vector>
#include <cstdlib>


namespace animals {

class Animal {
public:
    inline virtual void sound() { std::cout << "...\n"; }

    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    inline void sound() override { std::cout << "Woof!\n"; }
};

class Cat : public Animal {
public:
    inline void sound() override { std::cout << "Meow!\n"; }
};

}
