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
        unordered_map<int,ListNode*> m;
        ListNode* temp = head;
        int start = 1;
        int end = 0;

        
        while(temp){
            end++;
            m[end] = temp;
            temp = temp->next;
        }
        bool turnBack = false;
        ListNode* newHead = new ListNode(0);
        temp = newHead;
        cout << "size is " << end << endl;
        

        while(!m.empty()){
            if(turnBack == false){
                turnBack = true;
                // adds front
                temp->next = m[start];
                temp = temp->next;
                m.erase(start);
                start++;
                cout << "start is " << start << endl;
                

                

            }else{
                turnBack = false;
                // adds back
                temp->next = m[end];
                temp = temp->next;
                m.erase(end);
                end--;
                cout << "size is " << end << endl;

            }

        }

        temp->next = nullptr;

        
    }
};
