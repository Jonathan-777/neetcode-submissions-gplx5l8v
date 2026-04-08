/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

// options 1, use arr(easy), use l, r trick(hard) 3, use pq. previously i used a vector/arr because using l, r trick is verbose
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    
    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    

    ListNode* newHead = dummy->next;
    delete dummy; 
    delete toDelete; 
    
    return newHead;
}
};
