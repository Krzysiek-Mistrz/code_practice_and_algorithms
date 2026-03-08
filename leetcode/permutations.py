# Given an array nums of distinct integers, return all the possible . You can return the answer in any order.

# Example 1
# Input: nums = [1,2,3]
# Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        used = [False] * len(nums)
        
        def backtrack(current_permutation: List[int]):
            if len(current_permutation) == len(nums):
                result.append(list(current_permutation))
                return
            
            for i in range(len(nums)):
                if not used[i]:
                    used[i] = True
                    current_permutation.append(nums[i])
                    backtrack(current_permutation)
                    used[i] = False
                    current_permutation.pop()
        
        backtrack([])
        return result