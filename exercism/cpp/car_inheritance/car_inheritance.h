#include <iostream>
#include <string>
#include <cstdlib>


namespace cars {

class Engine {
public:
    int power;

    Engine(int p) : power(p) {}
};

class Car : public Engine {
public:
    std::string brand;

    Car(std::string b, int p) : Engine(p), brand(b) {}
};

}