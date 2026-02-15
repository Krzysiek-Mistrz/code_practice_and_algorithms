#include <iostream>
#include <vector>


class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid = nums.size() / 2;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }

        return left;
    }
};