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
        if(head == nullptr)return nullptr;

        vector<ListNode*> vec;
        ListNode* temp = head;
        while(temp){
            vec.push_back(temp);
            temp = temp->next;  
        }
        cout << vec.size();
        if(vec.size() <= 1){
            return head;
        }
        
        temp = vec[vec.size()-1];

        for(int i = vec.size()-2; i >= 0; i--){

            
                temp->next = vec[i];
                temp = temp->next;

    
            
        }
        temp->next = nullptr;
        return vec[vec.size()-1];
    }
};
