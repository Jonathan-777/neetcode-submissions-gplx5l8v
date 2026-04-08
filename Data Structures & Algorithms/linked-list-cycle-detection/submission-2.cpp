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
    bool hasCycle(ListNode* head) {
        unordered_map<int,ListNode*> m;
        ListNode* temp = head;
        while(temp){
            if(auto it = m.find(temp->val); it != nullptr){
                if(it->second == temp){
                    return true;
                }
            }

            m[temp->val] = temp;
            temp = temp->next;


        }
        return false;
        
    }
};
