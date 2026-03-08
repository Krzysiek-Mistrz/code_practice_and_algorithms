#include "car_inheritance.h"


namespace cars {

    int main(int argc, char** argv) {
        Car my_car("Toyota", 150);
        
        std::string brand = my_car.brand;
        int power = my_car.power;

        std::cout << "brand: " << brand << ", power: " << power << std::endl;

        return EXIT_SUCCESS;
    }

}