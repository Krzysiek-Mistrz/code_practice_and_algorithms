#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        
        int global_max = 2;
        
        for (int i = 0; i < n; ++i) {
            unordered_map<double, int> slope_counts;
            
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                
                double dy = points[j][1] - points[i][1];
                double dx = points[j][0] - points[i][0];
                
                double slope = (dx == 0) ? INFINITY : dy / dx;
                
                if (slope == -0.0) slope = 0.0;
                
                slope_counts[slope]++;
            }
            
            for (auto& p : slope_counts) {
                global_max = max(global_max, p.second + 1);
            }
        }
        
        return global_max;
    }
};