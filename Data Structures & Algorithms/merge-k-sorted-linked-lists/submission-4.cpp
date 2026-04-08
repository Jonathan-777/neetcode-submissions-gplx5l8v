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
    struct minH{
        bool operator()(ListNode*a , ListNode*b){
            return a->val > b->val;
        }

    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, minH> pq;
        ListNode* temp = nullptr;

        for(auto x: lists){
            temp = x;
            while(temp){
                pq.push(temp);
                temp = temp->next;
            }
        }
        ListNode* head = new ListNode(0);
        temp = head;

        while(!pq.empty()){
            temp->next = pq.top();
            pq.pop();
            temp = temp->next;
        }
        temp->next = nullptr;
        return head->next;
    }
};
