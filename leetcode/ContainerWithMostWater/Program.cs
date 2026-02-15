/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
*/

public class Solution {
    public static int MaxArea(int[] height) {
        int left = 0;
        int right = height.Length - 1;
        int max_area = 0;

        while (left < right)
        {
            int width = right - left;
            int temp_max_area = (height[left] > height[right]) ? (height[right] * width) : (height[left] * width);
            max_area = Math.Max(temp_max_area, max_area);

            if (height[left] > height[right])
                right--;
            else
                left++;
        }

        return max_area;
    }

    public static void Main(string[] args)
    {
        var height = new int[] {1,8,6,2,5,4,8,3,7};
        Console.WriteLine(MaxArea(height));
    }
}