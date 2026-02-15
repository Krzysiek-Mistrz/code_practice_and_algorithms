/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:
    0 <= j <= nums[i] and
    i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

#include <iostream>
#include <vector>


class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 1) return 0;

        int jumps = 0;
        int farthest = 0;
        int current_end = 0;

        for (int i = 0; i < n; i++) {
            farthest = std::max(farthest, i + nums[i]);

            //we only do jump after we finished making prev
            if (i == current_end) {
                jumps++;
                // where we can go the furthest
                current_end = farthest;
            }

            if (current_end >= n - 1) break;
        }

        return jumps;
    }
};