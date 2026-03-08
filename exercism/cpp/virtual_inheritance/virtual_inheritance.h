#include <iostream>
#include <filesystem>
#include <initializer_list>
#include <cstdlib>

// its alias u can do also: namespace v = std::vector; 4 example
namespace fs = std::filesystem;

class A {
public:
    int x;
};

class B : virtual public A {};

// virtual public = jesli ktos bedzie dziedziczyl po nas obu, to niech uzywa tej samej, wspolnej kopii klasy A
class C : virtual public A {};

class D : public B, public C {
public:
    D(std::initializer_list<int> list) {
        for (int i : list) 
            std::cout << i << ", ";
    }
};