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
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        ListNode* new_head = new ListNode(0);
        ListNode* temp = new_head;

        while(temp1 || temp2 || carry > 0){// assume each val is < 10
        
            int one_val = INT_MIN;
            int two_val =INT_MIN;
            int temp_val = 0;

            if(temp1){
                one_val = temp1->val;
            }
            if(temp2){
                two_val = temp2->val;
            }

            // populate temp_val
            if(one_val != INT_MIN && two_val != INT_MIN){
                temp_val = one_val + two_val;
            }else if(one_val != INT_MIN && two_val == INT_MIN){
                temp_val = one_val;
            }else if(one_val == INT_MIN && two_val != INT_MIN){
                temp_val = two_val;
            }else{

            }
            temp_val += carry;
            carry = 0;

            if(temp_val >= 10){
                carry = temp_val /10;
                temp_val = temp_val - 10;
                
            }

            temp->next = new ListNode(temp_val);
            temp = temp->next;
            if(temp1)temp1 = temp1->next;
            if(temp2)temp2 = temp2->next;
            cout << carry;
        }        
        
        temp->next= nullptr;
        return new_head->next;
    }
};
