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
    struct minHeapHelper{
        bool operator() (ListNode* a , ListNode* b){
            return a->val > b->val;
        }
    };


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>, minHeapHelper> name;

        ListNode* temp = nullptr;

        for(int i = 0 ; i < lists.size(); i++){
            temp = lists[i];
            while(temp){
                name.push(temp);
                temp = temp->next;
            }
        }

        ListNode* newHead = new ListNode(0);
        temp = newHead;

        while(!name.empty()){
            ListNode* aTempNode = name.top();
            name.pop();
            temp->next = aTempNode;
            temp = temp->next;

        }

        temp->next = nullptr;
        return newHead->next;
    }
};
