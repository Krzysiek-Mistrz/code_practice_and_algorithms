#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        if (k >= n / 2) {
            int max_profit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    max_profit += prices[i] - prices[i - 1];
                }
            }
            return max_profit;
        }

        vector<int> buy(k, INT_MIN);
        vector<int> sell(k, 0);

        for (int p : prices) {
            for (int j = 0; j < k; ++j) {
                buy[j] = max(buy[j], (j == 0 ? 0 : sell[j - 1]) - p);
                sell[j] = max(sell[j], buy[j] + p);
            }
        }

        return sell[k - 1];
    }
};