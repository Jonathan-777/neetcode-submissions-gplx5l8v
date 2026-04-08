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

    
        while(l1 || l2|| carry){
            int sum = 0;
            int l = 0;
            int lTwo = 0;
            if(l1){
                l = l1->val;
            }
            
            if(l2){
                lTwo = l2->val;
            }

            sum = (l + lTwo) + carry;

            if(sum >= 10){
                carry = sum / 10;
                sum = sum % 10;
            }else{
                carry = 0;
            }
            temp->next = new ListNode(sum);
            if(temp->next)temp = temp->next;
            

            if(l1 && l1->next){
                l1 = l1->next;
            }else{
                l1 = nullptr;
            }

            if(l2 && l2->next){
                l2 = l2->next;
            }else{
                l2 = nullptr;
            }
                       

        }

        temp->next = nullptr;
        return newHead->next;
        
    }
};
