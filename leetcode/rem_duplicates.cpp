#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

/*
plan:
1, 2, 2, 3, 4, 5, 5
*/

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        auto it = std::unique(nums.begin(), nums.end());
        nums.resize(std::distance(nums.begin(), it));
        return nums.size();
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> vec = {0,0,1,1,1,2,2,3,3,4};
    std::cout << sol.removeDuplicates(vec) << std::endl;
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
}