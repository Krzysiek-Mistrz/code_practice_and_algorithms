#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>


class Solution {
public:
    bool isPalindrome(std::string s) {
        for (int i = 0; i < s.length(); i++)
            if (!std::isalnum(s.at(i))) {
                s.erase(s.begin() + i);
                i--;
            }
        std::transform(s.begin(), s.end(), s.begin(), [](char c){return std::tolower(c);});
        for (int i = 0; i < s.length(); i++)
            if (s.at(i) != s.at(s.length() - i - 1))
                return false;
        return true;
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::cout << sol.isPalindrome("0P") << std::endl;
    // std::cout << sol.isPalindrome("A man, a plan, a canal: Panama") << std::endl;
}