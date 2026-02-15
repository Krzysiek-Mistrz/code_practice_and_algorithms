#include <iostream>
#include <map>


/*
Given two strings s and t, return true if t is an of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

*/

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) 
            return false;
        
        std::map<char, int> map1;
        std::map<char, int> map2;

        for (int i = 0; i < s.length(); i++) {
            if (map1[s[i]]) 
                map1[s[i]]++;
            else
                map1[s[i]] = 1;
        }
        for (int i = 0; i < t.length(); i++) {
            if (map2[t[i]]) 
                map2[t[i]]++;
            else
                map2[t[i]] = 1;
        }
        for (const auto& x : map1) {
            if (!map2[x.first] || map2[x.first] != x.second)
                return false;
        }

        return true;
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::cout << sol.isAnagram("anagram", "nagaram") << std::endl;
}