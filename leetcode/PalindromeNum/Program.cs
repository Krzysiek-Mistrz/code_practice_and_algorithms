namespace PalindromeNum
{
    public class Solution
    {
        public static bool IsPalindrome(int x)
        {
            string pal = System.Convert.ToString(x);
            for (int i = 0; i < pal.Length / 2; i++)
            {
                if (pal[i] != pal[pal.Length - i - 1])
                    return false;
            }
            return true;
        }

        public static void Main(string[] args)
        {
            System.Console.WriteLine(IsPalindrome(-121));
        }
    }
}
