# Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
# The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
# You must write an algorithm that runs in O(n) time and without using the division operation.

# Example 1:
# Input: nums = [1,2,3,4]
# Output: [24,12,8,6]

import math
from sys import prefix
from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        answer = [1] * n
        prefix_prod = 1
        suffix_prod = 1
        
        for i in range(n):
            answer[i] = prefix_prod
            prefix_prod *= nums[i]
            
        for i in range(n - 1, -1, -1):
            answer[i] *= suffix_prod
            suffix_prod *= nums[i]
            
        return answer