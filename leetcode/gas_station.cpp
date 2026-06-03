#include <vector>
#include <numeric>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int total_paliwo = 0;
        int aktualny_bak = 0;
        int start_index = 0;

        for (int i = 0; i < gas.size(); i++) {
            int bilans_stacji = gas[i] - cost[i];
            
            total_paliwo += bilans_stacji;
            aktualny_bak += bilans_stacji;

            if (aktualny_bak < 0) {
                start_index = i + 1;
                aktualny_bak = 0;
            }
        }

        if (total_paliwo < 0) {
            return -1;
        }

        return start_index;
    }
};