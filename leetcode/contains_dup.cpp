#include <iostream>
#include <unordered_map>
#include <vector>


class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> u_map;
        for (int i = 0; i < nums.size(); i++) {
            if (u_map.find(nums[i]) != u_map.end() && i - u_map[nums[i]] <= k)
                return true;
            u_map[nums[i]] = i;
        }
        return false;
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> vec = {1,2,3,1};
    std::cout << sol.containsNearbyDuplicate(vec, 3);
}