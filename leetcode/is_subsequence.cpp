#include <iostream>

// Given two strings s and t, return true if s is a subsequence 
// of t, or false otherwise.
// A subsequence of a string is a new string that is formed 
// from the original string by deleting some (can be none) 
// of the characters without disturbing the relative positions 
// of the remaining characters. (i.e., "ace" is a subsequence 
// of "abcde" while "aec" is not).


class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int s_ptr = 0;
        int t_ptr = 0;
        while (s_ptr < s.length() && t_ptr < t.length()) {
            if (s.at(s_ptr) == t.at(t_ptr)) {
                s_ptr++;
            }
            t_ptr++;
        }
        return s_ptr == s.length();
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::cout << sol.isSubsequence("aaaaaa", "bbaaaa") << std::endl;
}