#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int prev = 1, curr = 2, next;
        for (int i = 3; i <= n; i++) {
            next = prev + curr;
            prev = curr;
            curr = next;
        }

        return curr;
    }
};

int main() {
    Solution solution;
    int n;
    std::cout << "Enter the number of steps: ";
    std::cin >> n;
    std::cout << "Number of distinct ways to climb to the top: " << solution.climbStairs(n) << std::endl;
    return 0;
}
