from bisect import bisect_left

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        sub = []
        
        for x in nums:
            idx = bisect_left(sub, x)

            if idx == len(sub):
                sub.append(x)
            else:
                sub[idx] = x
                
        return len(sub)