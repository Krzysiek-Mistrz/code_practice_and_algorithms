#include <iostream>
#include <utility>


namespace project {
    template<typename T>
    void replace(T& a, T& b) {
        T temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }

    class Container {
    private:
        int* data;

    public:
        Container(int s) { data = new int[s]; }
        
        ~Container() { delete[] data; }

        Container(Container&& other) noexcept : data(other.data) {
            other.data = nullptr;
        }

        Container(const Container& other) = delete;
    };
}