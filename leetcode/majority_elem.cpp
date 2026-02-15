#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

/*
plan:
1) try to use some built in function in cpp 4 that
2) if !exist(fcn_builtin) -> 

Input: nums = [3,2,3]
Output: 3


*/


class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        // std::map<int, int> count_map;
        std::set<int> unique_vals(nums.begin(), nums.end());
        int majority_elem;
        for (auto elem : unique_vals) {
            // assuming there only one such elem
            if (std::count(nums.begin(), nums.end(), elem) > (nums.size() / 2)) {
                majority_elem = elem;
            }
        }
        return majority_elem;
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> vec = {2,2,1,1,1,2,2};
    std::cout << sol.majorityElement(vec) << std::endl;
}