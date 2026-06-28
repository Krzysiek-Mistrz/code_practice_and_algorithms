#include <queue>
#include <vector>

class MedianFinder {
private:
    std::priority_queue<int> small; // maxheap
    std::priority_queue<int, std::vector<int>, std::greater<int>> large; // minheap

public:
    MedianFinder() {}
    
    void addNum(int num) {
        small.push(num);
        
        large.push(small.top());
        small.pop();
        
        if (small.size() < large.size()) {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if (small.size() > large.size()) {
            return small.top();
        }
        return (small.top() + large.top()) / 2.0;
    }
};