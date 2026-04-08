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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        ListNode* temp = head;
        vector<ListNode*> v;
        while(temp){
            v.push_back(temp);
            temp = temp->next;

        }
        temp = newHead;

        for(int i = v.size()-1 ; i >= 0; i--){
            temp->next = v[i];
            temp = temp->next;



        }
        temp->next = nullptr;

        return newHead->next;
    }
};
