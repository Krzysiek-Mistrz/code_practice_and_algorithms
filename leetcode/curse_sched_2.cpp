#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> in_degree(numCourses, 0);
        
        for (const auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);    // creatin adjacency list
            in_degree[edge[0]]++;   // keeping track of in degrees 4 each course
        }
        
        std::queue<int> q;
        
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        
        std::vector<int> order;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            order.push_back(current);
            
            for (int neighbor : adj[current]) {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        if (order.size() == numCourses) {
            return order;
        }
        
        return {};
    }
};