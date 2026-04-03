# You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.
# You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
# Return the answers to all queries. If a single answer cannot be determined, return -1.0.
# Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.
# Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

# Example 1:
# Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
# Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
# Explanation: 
# Given: a / b = 2.0, b / c = 3.0
# queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
# return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
# note: x is undefined => -1.0

from collections import defaultdict
from email.policy import default
import queue
from typing import List
from collections import deque


class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = defaultdict(list)
        
        for (u, v), val in zip(equations, values):
            graph[u].append((v, val))
            graph[v].append((u, 1.0 / val))
            
        def bfs(start, end):
            if start not in graph or end not in graph:
                return -1.0
            
            if start == end:
                return 1.0
            
            queue = deque([(start, 1.0)])
            visited = {start}
            
            while queue:
                curr, curr_val = queue.popleft()
                
                if curr == end:
                    return curr_val
                
                for neighbour, weight in graph[curr]:
                    if neighbour not in visited:
                        visited.add(neighbour)
                        queue.append((neighbour, curr_val * weight))
                        
            return -1.0
        
        return [bfs(q[0], q[1]) for q in queries]