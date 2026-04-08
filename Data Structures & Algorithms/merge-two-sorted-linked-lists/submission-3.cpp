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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;

        while(temp1 || temp2){
            if(temp1 && temp2){
                temp->next = (temp1->val < temp2->val)? temp1 : temp2;
                temp = temp->next;

                if((temp1->val < temp2->val)){
                    temp1 = temp1->next;
                }else{
                    temp2 = temp2->next;
                }

            }else if(temp1 && !temp2){
                temp->next = temp1;
                temp1 = temp1->next;
                temp = temp->next;
            }else{
                temp->next = temp2;
                temp2 = temp2->next;
                temp = temp->next;
            }

        }
        if(temp1 == nullptr && temp2 == nullptr)cout<< "hello";
        temp->next = nullptr;
        return newHead->next;
    }
};
