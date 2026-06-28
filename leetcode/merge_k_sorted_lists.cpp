#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> min_heap;

        for (ListNode* list : lists) {
            if (list != nullptr) {
                min_heap.push(list);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!min_heap.empty()) {
            ListNode* smallest = min_heap.top();
            min_heap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != nullptr) {
                min_heap.push(smallest->next);
            }
        }

        ListNode* result = dummy->next;
        delete dummy;
        
        return result;
    }
};