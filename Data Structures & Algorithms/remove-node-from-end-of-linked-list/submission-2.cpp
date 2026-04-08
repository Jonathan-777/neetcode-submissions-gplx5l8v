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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* deleteThisNode = head;
        ListNode* temp = head; 
        int targetNum = 0;
        while(temp){
            size++;
            temp = temp ->next;
            if(temp == nullptr){
                targetNum  = size - (n - 1);

            }

        }
        cout << "target num is : " << targetNum << endl;
        temp = head;
        ListNode* newHead = new ListNode(0,head);

        while(targetNum > 0){
            targetNum--;
            if(targetNum == 0){
                if(temp == deleteThisNode){
                    newHead->next = deleteThisNode->next;
                    delete deleteThisNode;
                    break;
                }else{
                temp->next = deleteThisNode->next;
                deleteThisNode->next == nullptr;
                delete deleteThisNode;
                }
            
                
            }

            temp = deleteThisNode;
            deleteThisNode = deleteThisNode->next;
        }

        return newHead->next;
        

        
    }
};
