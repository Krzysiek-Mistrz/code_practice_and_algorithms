#include <iostream>


/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true
Explanation:
The strings s and t can be made identical by:
    Mapping 'e' to 'a'.
    Mapping 'g' to 'd'.
*/

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        int mapS[256] = {0};
        int mapT[256] = {0};
        for (int i = 0; i < s.length(); i++) {
            if (mapS[s[i]] != mapT[t[i]])
                return false;
            mapS[s[i]] = i+1;
            mapT[t[i]] = i+1;
        }
        return true;
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::cout << sol.isIsomorphic("foo", "bar") << std::endl;
}