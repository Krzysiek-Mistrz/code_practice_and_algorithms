#!/usr/bin/env python3


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s2 = s.split()
        return len(s2[-1])


def main():
    sol = Solution()
    print(sol.lengthOfLastWord("   fly me   to   the moon  "))
    

if __name__ == "__main__":
    main()