// Given two binary strings a and b, return their sum as a binary string.
// Example 1:
// Input: a = "11", b = "1"
// Output: "100"
// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"

#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>


class Solution {
public:
    static int to_decimal(const std::string& number, int base) {
        int decimal = 0;
        int power = 0;

        for (int i = number.length() - 1; i >= 0; i--) {
            decimal += char_to_value(number[i]) * std::pow(base, power++);
        }

        return decimal;
    }

    static std::string from_decimal(int decimal, int base) {
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

    std::string add_binary(std::string a, std::string b) {
        long long a_dec = to_decimal(a, 2);
        long long b_dec = to_decimal(b, 2);
        long long sum = a_dec + b_dec; // Use long long to avoid overflow
        std::string result = from_decimal(sum, 2);
        return result;
    }

    std::string addBinary(std::string a, std::string b) {
        std::string result = "";

        int i = a.length() - 1;
        int j = b.length() - 1;
        int digit_a, digit_b, total;
        int carry = 0;

        while (i >= 0 or j >= 0 or carry) {
            digit_a = (i >= 0 ? (int)a[i] - '0' : 0);
            digit_b = (j >= 0 ? (int)b[j] - '0': 0);
            total = digit_a + digit_b + carry;
            result.push_back((total % 2) + '0');
            carry = total / 2;
            i--;
            j--;
        }

        std::reverse(result.begin(), result.end());

        return result;
    }

private:
    static int char_to_value(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'A' && c <= 'F') return c - 'A' + 10;
        if (c >= 'a' && c <= 'f') return c - 'a' + 10;
        throw std::invalid_argument("Invalid digit");
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::string a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    std::string b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
    std::cout << sol.add_binary(a, b) << std::endl; // Example 2: Output should be "10101"
}
