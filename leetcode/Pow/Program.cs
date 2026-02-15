public class Solution {
    public double MyPow(double x, int n) {
        if (x == 1.0 || x == 0.0)
        {
            return (x == 1) ? 1.0 : 0.0;
        }
        
        long absN = Math.Abs((long)n);
        double res = 1.0;
        while (absN > 0) {
            if ((absN & 1) == 1) {
                res *= x;
            }
            x *= x;
            absN >>= 1;
        }

        return n < 0 ? 1 / res : res;
    }

    public static void Main(string[] args) {
        Solution sol = new Solution();
        Console.Write(sol.MyPow(2.1, 3));
    }
}