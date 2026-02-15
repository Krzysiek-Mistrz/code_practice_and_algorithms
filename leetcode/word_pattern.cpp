#include <iostream>
#include <map>
#include <sstream>
#include <string>


/*
290. Word Pattern
Easy
Topics
premium lock iconCompanies
Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:
    Each letter in pattern maps to exactly one unique word in s.
    Each unique word in s maps to exactly one letter in pattern.
    No two letters map to the same word, and no two words map to the same letter.

    Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Explanation:
The bijection can be established as:
    'a' maps to "dog".
    'b' maps to "cat".
*/

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) const {
        /**
        * @brief Given a pattern and a string s, find if s follows the same pattern.
        * @param pattern The pattern string.
        * @param s The string to check against the pattern.
        * @return True if the string follows the same pattern, false otherwise.
        */
        std::map<char, std::string> map;
        std::stringstream ss(s);
        std::string wrd;
        std::map<std::string, int> temp_map;
        int i = 0; 
        
        while (ss >> wrd) { 
            if (i >= pattern.length()) return false;            
            char c = pattern[i];
            if (map.find(c) == map.end()) {
                if (temp_map.find(wrd) != temp_map.end()) 
                    return false;
                map[c] = wrd;
                temp_map[wrd] = 1;
            } else {
                if (map[c] != wrd)
                    return false;
            }
            i++;
        }

        return i == pattern.length();
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::cout << sol.wordPattern("abba", "dog dog dog dog") << std::endl;
}