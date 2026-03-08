#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>


namespace project {

struct GreaterThan {
    int threshold;

    GreaterThan(int t) : threshold(t) {}

    bool operator()(int x) const { return x > threshold; }
};

}