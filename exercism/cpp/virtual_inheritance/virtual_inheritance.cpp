#include "virtual_inheritance.h"


int main(int argc, char** argv) {
    fs::path p = fs::current_path();

    for (const auto& entry : fs::directory_iterator(p)) {
        std::cout << entry.path().filename() << '\n';
    }

    D object{1, 2, 4, 5};
    
    return EXIT_SUCCESS;
}