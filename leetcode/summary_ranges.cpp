#include <vector>
#include <string>
#include <iostream>


class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        /**
        * @brief Generates a summary of ranges in a vector of integers.
        * @param nums The vector of integers to summarize.
        * @return A vector of strings representing the summary ranges.
        *
        * This function takes a vector of integers and generates a summary of the ranges
        * present in the vector. The summary is represented as a vector of strings, where
        * each string represents a range or a single integer.
        */
        std::vector<std::string> res;
        for (int i = 0; i < nums.size(); ++i) {
            int j = i;
            while (j + 1 < nums.size() && nums[j+1] == nums[j] + 1)
                ++j;
            if (j > i)
                res.push_back(std::to_string(nums[i]) + "->" + std::to_string(nums[j]));
            else
                res.push_back(std::to_string(nums[i]));
            i = j;
        }
        return res;
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> nums = {0, 1, 2, 4, 5, 7};
    for (const auto& elem : sol.summaryRanges(nums))
        std::cout << elem << std::endl;
}