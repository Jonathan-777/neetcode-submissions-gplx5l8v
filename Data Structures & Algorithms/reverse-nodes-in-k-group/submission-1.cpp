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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr)return head;

        vector<ListNode*> nodesVec;
        ListNode* temp = head;
        ListNode* newHead = new ListNode(0);
        while(temp){
            nodesVec.push_back(temp);
            temp = temp->next;
        }
        if(k > nodesVec.size())return head;
        int counter = 0;
        temp = newHead;

        for(int i = 0; i < nodesVec.size();i++){
            if(counter  < k){
             counter++;
            

            }
            
            if(counter == k){
                for(int z = i; z >= i-(k-1) ; z--){
                    temp->next = nodesVec[z];
                    temp = temp->next;
                    cout << "adding " << nodesVec[z]->val << " counter is : " << counter <<endl;
                }

                counter = 0;

            }else if(i == nodesVec.size()-1 && counter < k){
                for(int z = i-counter+1; z < nodesVec.size(); z++){
                    temp->next = nodesVec[z];
                    temp = temp->next;
                    cout << "adding " << nodesVec[z]->val << endl;

                }

            }else{

            }

        }
        temp->next = nullptr;
        return newHead->next;

    }
};
