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

        vector<ListNode*> v;
        ListNode* temp = head;
        ListNode* ans = nullptr;
        while(temp != nullptr){
            v.push_back(temp);
            temp = temp->next;

        }
        ans = v[v.size() -1];
        temp = ans;

        for(int i = v.size()-2 ; i >= 0; i--){
            temp->next = v[i];
            temp = v[i];
        }
        temp->next = nullptr;
        return ans;
    }
};
