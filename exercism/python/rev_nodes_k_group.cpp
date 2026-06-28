class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }
        
        if (count == k) {
            curr = head;
            ListNode* prev = nullptr;
            ListNode* next_node = nullptr;
            
            for (int i = 0; i < k; ++i) {
                next_node = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next_node;
            }
            
            if (next_node != nullptr) {
                head->next = reverseKGroup(next_node, k);
            }
            
            return prev;
        }
        
        return head;
    }
};