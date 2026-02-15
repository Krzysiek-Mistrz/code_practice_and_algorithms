public class Solution {

    public int CountZeros(int n) {
        Func<int, int> Count = (num) => {
            int count = 0;
            while (num > 0 && num % 10 == 0) {
                num /= 10;
                count++;
            }
            return count;
        };
        return Count(n);
    }

    public int TrailingZeroes(int n) {
        int count = 0;
        for (int i = 5; n / i >= 1; i *= 5) {
            count += n / i;
        }
        return count;
    }

    public static void Main(string[] args)
    {
        Solution sol = new Solution();
        Console.WriteLine(sol.TrailingZeroes(5));
    }
}