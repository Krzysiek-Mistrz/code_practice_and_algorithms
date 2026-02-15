#include <iostream>
#include <map>
#include <string>


class Solution {
public:
    int romanToInt(std::string s) {
        std::map<char, int> map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int len = (int)s.size();
        int conv_val = 0;
        for (int i = 0; i < len; i++) {
            if (i + 1 == len) {
                conv_val += map.at(s.at(i));
                break;
            }
            if (map.at(s.at(i+1)) > map.at(s.at(i))) {
                conv_val += map.at(s.at(i+1)) - map.at(s.at(i));
                if (i + 1 < len)
                    i++;
            }
            else {
                conv_val += map.at(s[i]);
            }
        }
        return conv_val;
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::cout << sol.romanToInt("MCMXCIV");
}