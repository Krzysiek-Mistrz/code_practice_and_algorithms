#include <vector>

class Solution {
private:
    bool has_cycle(int node, std::vector<std::vector<int>>& adj, std::vector<int>& visited) {
        if (visited[node] == 1) return true;  
        if (visited[node] == 2) return false; 
        
        visited[node] = 1; 
        
        for (int neighbor : adj[node]) {
            if (has_cycle(neighbor, adj, visited)) {
                return true;
            }
        }
        
        visited[node] = 2; 
        return false;
    }

public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        for (const auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }
        
        std::vector<int> visited(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (has_cycle(i, adj, visited)) {
                    return false; 
                }
            }
        }
        
        return true; 
    }
};