# Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
# You must implement a solution with a linear runtime complexity and use only constant extra space.
# Example 1:
# Input: nums = [2,2,3,2]
# Output: 3

from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()
        
        for i in range(0, len(nums) - 2, 3):
            if nums[i] != nums[i + 1]:
                return nums[i]
        
        return nums[-1]