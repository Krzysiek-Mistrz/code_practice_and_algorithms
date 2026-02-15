#include <iostream>
#include <vector>
#include <deque>

/*

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
*/


class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        std::deque<int> deque(nums.begin(), nums.end());
        int temp_val;
        while (k > 0) {
            temp_val = deque.back();
            deque.pop_back();
            deque.push_front(temp_val);
            k--;
        }
        nums.clear();
        nums.assign(deque.begin(), deque.end());
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> vec = {1,2,3,4,5,6,7};
    int k = 3;
    sol.rotate(vec, k);
    for (const auto& elem : vec) 
        std::cout << elem << " ";
}