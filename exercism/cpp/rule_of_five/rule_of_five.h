#pragma once

#include <iostream>
#include <string>
#include <cstdlib>


namespace warehouses {

class Warehouse {
private:
    std::string* data;

public:
    Warehouse(std::string d) : data(new std::string(d)) {}

    ~Warehouse() { delete data; }

    Warehouse(const Warehouse& other) {
        data = new std::string(*(other.data));
    }

    inline std::string get_data() const { return *(data); }
    
    inline void set_data(std::string d) { *data = d; }
};

}
