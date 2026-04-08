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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;
        ListNode* prev = nullptr;

        while(l1 || l2){
            int ith_place = 1;
            int l1Num= 0;
            int l2Num=0;
            if(l1){
                l1Num = l1->val;
            }
            if(l2){
                l2Num = l2->val;
            }
            int sum = l1Num + l2Num + carry;
            carry = 0;
            if(sum >= 10){
                carry = sum / 10;
                sum = sum % 10;
            }
            temp->val = sum;
 
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;
            
            if(l1 || l2){
            temp->next = new ListNode(0);
            prev = temp;
            temp = temp->next;

            }

        }
        temp->next = ( carry == 0) ? nullptr : new ListNode(carry);
        if(temp->next != nullptr){
            temp = temp->next;
            temp->next = nullptr;
        }
        return newHead;
        
    }
};
