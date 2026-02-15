/*
You are given a large integer represented as an integer array 
digits, where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least 
significant in left-to-right order. The large integer does not 
contain any leading 0's.
Increment the large integer by one and return the resulting 
array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
*/

namespace PlusOne
{
    public class Solution
    {
        public static int[] PlusOne(int[] digits)
        {
            for (int i = digits.Length - 1; i >= 0; i--)
            {
                if (digits[i] != 9) {
                    digits[i]++;
                    break;
                } else if (i != 0) {
                    digits[i] = 0;
                    continue;
                } else {
                    digits[i] = 0;
                    int[] temp_digits = new int[digits.Length + 1];
                    temp_digits[0] = 1;
                    for (int j = 1; j < digits.Length + 1; j++)
                        temp_digits[j] = digits[j - 1];
                    return temp_digits;
                }
            }
            return digits;
        }

        public static void Main(string[] args)
        {
            int[] digits = {9};
            digits = PlusOne(digits);
            foreach (int digit in digits) 
                System.Console.Write(digit + " ");
        }
    }
}