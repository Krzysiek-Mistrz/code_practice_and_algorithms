#include <iostream>

/*
123

123 / 10 = 12, 3
12 / 10 = 1, 2
1 / 10 = 0, 1

2
4
16
37
58
89
145
42
20
4
*/


class Solution {
public:
    int getNext(int n) {
        int rem_sum = 0;
        int division = n;
        
        while (division) {
            rem_sum += (division % 10) * (division % 10);
            division /= 10;
        }

        return rem_sum;
    }


    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        
        while (slow != fast && fast != 1) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        
        return fast == 1;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::cout << sol.isHappy(2) << std::endl;
}