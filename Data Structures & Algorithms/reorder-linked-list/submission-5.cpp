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
        vector<ListNode*> v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp);
            temp= temp->next;
        }

        auto it_l = v.begin();
        auto it_r = v.end()-1;
        bool turnR = false;
        ListNode* newHead = new ListNode(0);
        temp = newHead;
        while(it_l <= it_r){
            cout << "here";
            if(!turnR){
                temp->next = *it_l;
                it_l = next(it_l);
            }else if(turnR){
                temp->next = *it_r;
                it_r = prev(it_r);
            }
            temp = temp->next;
            turnR = !turnR;
        }
        temp->next = nullptr;

        
    }
};
