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
    struct min_heap_param{
        bool operator ()(ListNode* a, ListNode*b ){
            return a->val > b->val;
        }

    };
    //////////////////////
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, min_heap_param> pq;
        for(auto temp: lists){
            while(temp){
                pq.push(temp);
                temp=temp->next;
            }
        }
    unique_ptr<ListNode> new_head(new ListNode(0));// also  std::unique_ptr<ListNode> unique_head = std::make_unique<ListNode>(0);  works
    ListNode* temp = new_head.get();

        while(!pq.empty()){
            ListNode* small = pq.top();
            pq.pop();
            temp->next = small;
            temp= temp->next;

        }

        temp->next = nullptr;
        
        return new_head->next;


    }



};
