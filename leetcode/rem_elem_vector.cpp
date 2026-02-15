#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        while (std::find(nums.begin(), nums.end(), val) != nums.end()) {
            nums.erase(std::find(nums.begin(), nums.end(), val));
        }
        return nums.size();
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> vec = {3, 2, 2, 3};
    std::printf("%d", sol.removeElement(vec, 3));
}