#include <iostream>
#include <vector>
#include <algorithm>

/*
    1, 1, 1, 2, 3
    1, 3, 3, 4, 5, 6

    plan:
    polaczyc 2 tablice -> posortowac rosnaco
*/

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        // for (int i = 0; i < n; i++) {
        //     nums1.pop_back();
        // }
        nums1.erase(nums1.end() - n, nums1.end());
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        std::sort(nums1.begin(), nums1.end());
    }
};

int main(int argc, const char** argv) {
    std::vector<int> nums1 = {1,2,3,0,0,0}; 
    int m = 3;
    std::vector<int> nums2 = {2,5,6}; 
    int n = 3;
    Solution sol;
    sol.merge(nums1, m, nums2, n);
    for (auto elem : nums1) {
        std::cout << elem << " ";
    }
}