#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        
        for (int i = 0; i < n; ++i) {
            projects[i] = {capital[i], profits[i]};
        }
        
        sort(projects.begin(), projects.end());
        priority_queue<int> max_profit_heap;
        int idx = 0;
        
        for (int i = 0; i < k; ++i) {
            while (idx < n && projects[idx].first <= w) {
                max_profit_heap.push(projects[idx].second);
                idx++;
            }
        
            if (max_profit_heap.empty()) {
                break;
            }
            
            w += max_profit_heap.top();
            max_profit_heap.pop();
        }
        
        return w;
    }
};