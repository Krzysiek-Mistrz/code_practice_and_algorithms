#include <vector>
#include <iostream>

/*
plan:
[1,1,1,2,2,3]

iterowac po calej tablicy
jezeli tab[i+1] = tab[i] = tab[i+2] to usun zupelnie i+2 i kolejne wystapienia ktore po nim sa
[1,1,1,2,2,3]
*/

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() == 1) 
            return 1;
        for (int i = 0; i < nums.size() - 2; i++) {
            int elem = nums[i];
            while ((i+2 < nums.size()) && elem == nums[i+2]) {
                nums.erase(nums.begin() + i + 2);
            }
            // for (int j = i + 2; j < nums.size() - 2; j++) {
            //     if (elem == nums[j]) {
            //         nums.erase(nums.begin() + j);
            //     }
            // }
        }
        return nums.size();
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> vec = {1,1,1};
    std::cout << sol.removeDuplicates(vec) << std::endl;
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
}