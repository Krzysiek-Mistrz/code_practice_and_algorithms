#include <iostream>
#include <exception>
#include <stdexcept>
#include <cstdlib>


namespace devices {

class DeviceError : public std::exception {
public:
    // noexcept = 4 sure this function wont ever return an exception, this statement provides that compilator will do excatly what u said when 4 example moving a value
    // noexcept do konstruktorow przenoszacych i operatorow przypisania przenoszacego
    inline const char* what() const noexcept override { return "It is not a printer!"; }
};

class Device {
public:
    virtual ~Device() = default;
};

class Printer : public Device {
public:
    inline void print() { std::cout << "Printing ...\n"; }
};

class Scanner : public Device {};

void check_and_print(Device* u);

}