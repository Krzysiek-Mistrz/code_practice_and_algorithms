#include <iostream>
#include <vector>


class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max_profit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices.at(i) < prices.at(i+1)) {
                max_profit += (prices.at(i+1) - prices.at(i));
            } 
        }
        return max_profit;
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::vector<int> prices = {7,1,5,3,6,4};
    std::cout << sol.maxProfit(prices) << std::endl;
}