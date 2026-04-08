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
    ListNode* reverseList(ListNode* head) {// switch in place 
        ListNode* curr = nullptr;
        ListNode* prev = head;

        while(prev){
            ListNode* temp = prev->next;
            prev->next = curr;
            curr = prev;
            prev = temp;

        }

        return curr;
    }
};
