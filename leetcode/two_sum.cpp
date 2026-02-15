#include <iostream>
#include <vector>
#include <unordered_map>


/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

class Solution {
public:

    // std::vector<int> twoSum(std::vector<int>& nums, int target) {
    //     int first_num;
    //     int second_num;
    //     int i = 0;
    //     while (first_num + second_num != target) {
    //         if (i < nums.size())
    //             first_num = nums[i];
    //         for (int j = i + 1; j < nums.size() - 1; j++) {
    //             second_num = nums[j];
    //             if (first_num + second_num == target) {
    //                 return {i, j};
    //             }
    //         }   
    //         i++;
    //     }
    //     return {0, 0};
    // }

    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        
        for (int i = 0; i < nums.size(); i++) {
            int subtraction = target - nums[i];
            
            if (map.find(subtraction) != map.end())
                return {map[subtraction], i};
            
            map[nums[i]] = i;
        }
        return {};
    }
};



int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> nums {3,2,4}; 
    int target = 6;
    for (const auto& x : sol.twoSum(nums, target)) 
        std::cout << x << " ";
}