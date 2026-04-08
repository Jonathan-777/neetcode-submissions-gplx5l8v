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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }

        if (count == k) {
            ListNode* prev = reverseKGroup(curr, k);
            while (count > 0) {
                ListNode* next = head->next;
                head->next = prev;
                prev = head;
                head = next;
                count--;
            }
            head = prev;
        }
        return head;
    }
};