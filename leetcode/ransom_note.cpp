#include <iostream>
#include <map>


/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

*/

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::map<char, int> map1;
        std::map<char, int> map2;
        for (int i = 0; i < ransomNote.length(); i++) {
            if (map1[ransomNote[i]]) 
                map1[ransomNote[i]]++;
            else
                map1[ransomNote[i]] = 1;
        }
        for (int i = 0; i < magazine.length(); i++) {
            if (map2[magazine[i]]) 
                map2[magazine[i]]++;
            else
                map2[magazine[i]] = 1;
        }
        for (const auto& x : map1) {
            if (!map2[x.first] || map2[x.first] < x.second)
                return false;
        }
        return true;
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::cout << sol.canConstruct("aa", "aab") << std::endl;
}