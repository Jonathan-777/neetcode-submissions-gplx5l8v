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
    struct heapHelper{
        bool operator() (ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        priority_queue<ListNode*,vector<ListNode*>,heapHelper> heapTree;
        ListNode* temp = list1;
        while(temp){
            heapTree.push(temp);
            temp = temp->next;
        }
        temp = list2;
        while(temp){
            heapTree.push(temp);
            temp = temp->next;
        }



        ListNode* newHead = new ListNode(0);
         temp = newHead;

        while(!heapTree.empty()){
            cout << "adding node " << heapTree.top()->val;
            temp->next = heapTree.top();
            heapTree.pop();
            temp = temp->next;

        }
        temp->next = nullptr;
        return newHead->next;
        
    }

};
