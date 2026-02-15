#!/usr/bin/env python3
from typing import List


class Solution:
    # def longestCommonPrefix(self, strs: List[str]) -> str:
    #     min_len = 100
    #     for str in strs:
    #         if len(str) < min_len:
    #             min_len = len(str)
    #     lcp = ""
    #     for i in range(len(strs)-1):
    #         for j in range(min_len):
    #             if j >= len(strs[i]):
    #                 return strs[i]
    #             if strs[i][j] == strs[i+1][j]:
    #                 lcp += strs[i][j]
    #             else:
    #                 break
    #         strs[i+1] = lcp
    #         if not strs[i+1]:
    #             return ""
    #         lcp = ''
    #     return strs[-1]
    
    def longestCommonPrefix(self, strs: List[str]) -> str:
        lcp = strs[0]
        for i in range(1, len(strs)):
            while strs[i].find(lcp) != 0:
                lcp = lcp[:-1]
        return lcp
    

def main():
    sol = Solution()
    print(sol.longestCommonPrefix(["flower","flow","flight"]))
    

if __name__ == "__main__":
    main()