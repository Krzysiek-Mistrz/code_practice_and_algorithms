#include <iostream>
#include <vector>
#include <string>


void print(int n) {
    std::cout << "int: " << n << std::endl;
}

void print(std::string s) {
    std::cout << "string: " << s << std::endl;
}

void print(const std::vector<int>& v) {
    std::cout << "vector: ";

    for (auto elem : v) {
        std::cout << elem << " ";
    }

    std::cout << "\n";
}