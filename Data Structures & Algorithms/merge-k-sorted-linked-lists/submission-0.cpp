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
    struct minHeap{
        bool operator()(ListNode* a, ListNode* b){
            return  a->val >=  b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, minHeap> heap;
        

        for(auto it = lists.begin(); it != lists.end(); ++it){
            ListNode* temp = (*it);
            while(temp){
                heap.push(temp);
                temp = temp->next;
            }
        }

        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;

        while(!heap.empty()){
            temp->next = heap.top();
            heap.pop();
            temp = temp->next;
        }
        temp->next = nullptr;
        return newHead->next;
    }
};
