#include <iostream>
#include <cstdlib>


namespace robots {

class Robot {
private:
    int id;

public:
    static int num_of_robots;

    Robot() : id(++num_of_robots) {}

    static inline int get_num_of_robots() { return num_of_robots; }
};

}