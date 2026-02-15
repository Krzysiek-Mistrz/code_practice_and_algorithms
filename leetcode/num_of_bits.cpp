#include <iostream>
#include <string>

class Solution {
public:
    int hammingWeight(int n) {
        std::string binary = from_decimal(n, 2);
        int count = 0;
        for (int i = 0; i < binary.length(); i++)
            if (binary[i] == '1')
                count++;

        return count;
    }

    std::string from_decimal(int decimal, int base) {
        if (decimal == 0) 
            return "0";

        const std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string result;

        while (decimal > 0) {
            result = digits[decimal % base] + result;
            decimal /= base;
        }

        return result;
    }
};