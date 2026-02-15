// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example 1:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty())
            return {};
        
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& int1, std::vector<int>& int2) {
            return int1[0] < int2[0];
        });

        std::vector<std::vector<int>> merged;
        merged.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            std::vector<int>& lastMerged = merged.back();

            if (intervals[i][0] <= lastMerged[1]) {
                lastMerged[1] = std::max(lastMerged[1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};