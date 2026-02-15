#include <algorithm>
#include <iostream>
#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::vector<ListNode*> vec;
        while (head && head->next) {
            if (std::find(vec.begin(), vec.end(), head) != vec.end()) {
                return true;
            }
            vec.push_back(head);
            head = head->next;
        }
        return false;
    }
};


int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    std::cout << sol.hasCycle(head) << std::endl;
}