#!/usr/bin/env python3


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)
    

def main():
    sol = Solution()
    print(sol.strStr("sadbutsad", "sad"))
    
    
if __name__ == "__main__":
    main()