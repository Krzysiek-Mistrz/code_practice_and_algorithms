/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a whose sum is greater than or equal to target. If 
there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
*/

#include <vector>
#include <algorithm>
#include <climits>


class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int n = nums.size();
        int min_len = INT_MAX;
        int left = 0;
        int current_sum = 0;

        for (int right = 0; right < nums.size(); ++right) {
            current_sum += nums[right];

            while (current_sum >= target) {
                min_len = std::min(min_len, right - left + 1);
                current_sum -= nums[left];
                left++;
            }
        }

        return (min_len == INT_MAX) ? 0 : min_len;
    }
};