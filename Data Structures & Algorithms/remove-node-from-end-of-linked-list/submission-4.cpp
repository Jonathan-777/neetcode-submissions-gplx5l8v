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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> vec;
        ListNode* temp = head;
        while(temp){
            vec.push_back(temp);
            temp = temp->next;
        }
        for(int i = vec.size()-1; i >= 0;i--){
            if(n==1 && i != 0){
                vec[i-1]->next = vec[i]->next;
            }else if( n== 1 && i == 0){
                return head->next;
            }
            n--;
        }
        return head;
    }
};
