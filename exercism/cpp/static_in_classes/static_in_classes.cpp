#include "static_in_classes.h"


namespace robots {
    int main(int argc, char** argv) {
        int num = Robot::num_of_robots;

        std::cout << "num of robots: " << num << std::endl;

        return EXIT_SUCCESS;
    }
}