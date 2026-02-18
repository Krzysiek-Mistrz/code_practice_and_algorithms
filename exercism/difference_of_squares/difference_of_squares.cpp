#include "difference_of_squares.h"


namespace difference_of_squares {

int square_of_sum(int n) {
    return (((1 + n) / 2.0) * n) * (((1 + n) / 2.0) * n);
}

int sum_of_squares(int n) {
    int sum_of_sq{0};

    for (int i = 1; i <= n; i++) {
        sum_of_sq += i * i;
    }

    return sum_of_sq;
}

int difference(int n) {
    return square_of_sum(n) - sum_of_squares(n);
}

}  // namespace difference_of_squares
