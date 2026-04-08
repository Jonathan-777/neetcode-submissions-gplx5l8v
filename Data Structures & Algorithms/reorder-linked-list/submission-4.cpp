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
    
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        ListNode* temp = head;
        while(temp){
            vec.push_back(temp);
            temp= temp->next;
        }

        int i = 0;
        int j = vec.size()-1;
        ListNode* newHead = new ListNode(0);
        temp = newHead;
        bool iTurn = true;

        while(i <= j){
            if(iTurn){
                temp->next = vec[i++];
                temp = temp->next;
                iTurn = false;
            }else{
                temp->next = vec[j--];
                temp = temp->next;
                iTurn = true;
            }


        }
        temp->next = nullptr;

        
    }
};
