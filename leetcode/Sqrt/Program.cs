public class Solution {
    public int MySqrt(int x) {
        return (int)(Math.Sqrt(x));
    }

    public static void Main(string[] args) {
        Solution sol = new Solution();
        Console.Write(sol.MySqrt(8));
    }
}