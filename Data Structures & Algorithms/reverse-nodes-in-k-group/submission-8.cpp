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
        ListNode* prev_loop = nullptr;

        bool connect = false;
        bool first = true;
        while(curr){
            ListNode* slow = curr;
            ListNode* current_group_tail = slow;

            int count = k-1 ;// to keep correct count ALWAYS make sure we start counting at node 1 of count

            while(count > 0){
                if(curr) curr = curr->next;
                count--;
            }
            if(!curr)break;

            ListNode* next_start = curr->next;
            if(first){
                head = curr;
                first  = false;
            }

            if(prev_loop != nullptr){////////////////////////  connect the prev_loop with new curr aka new trailing end aka OLD leader
                prev_loop->next = curr;
            }
            
            while(slow != curr){
                
                ListNode* temp_slow_helper = slow->next;
                slow->next = curr->next;
                curr->next = slow;
                slow = temp_slow_helper;
            }
            prev_loop = current_group_tail;
            curr = next_start;
            connect = true;
        }
        
        return head;
        
    }
};
