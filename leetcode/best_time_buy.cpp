#include <iostream>
#include <ostream>
#include <vector>


/*
plan:
wybrac max z tablicy i odnjac od niego min z 
tablicy i essa tylko pamietac o tym ze indeks z 
wiek elem wiekszy od indeksu z min elem
*/

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // int max_diff = -1000;
        // for (int k = prices.size() - 1; k > 0; k--) {
        //     for (int i = 0; i < k; i++) {
        //         max_diff = (prices.at(k) - prices.at(i) > max_diff) ? (prices.at(k) - prices.at(i)) : max_diff;
        //     }
        // }
        // return max_diff < 0 ? 0 : max_diff;
        int max_diff = -1000000;
        int min = 1000000;
        int curr_price;
        for (int i = 0; i < prices.size(); i++) {
            if (prices.at(i) < min)
                min = prices.at(i);
            curr_price = prices.at(i) - min;
            if (curr_price > max_diff)
                max_diff = curr_price;
        }
        return max_diff < 0 ? 0 : max_diff;
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> prices {7,1,5,3,6,4};
    std::cout << sol.maxProfit(prices) << std::endl;
}