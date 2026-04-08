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
    //options 1(use priority queue) , 2(arr of pointers), 3(use the logic of merge sort(fastest))
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* new_head = new ListNode(0);
        ListNode* temp = new_head;

        while(list1 || list2){

            if(list1 && !list2){
                temp->next = list1;
                list1 = list1->next;
            }else if(list2 && !list1){
                temp->next = list2;
                list2 = list2->next;

            }else if(list1->val > list2->val){
                temp->next = list2;
                list2 = list2->next;
            }else if( list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }

            temp = temp->next;
        }


        temp->next = nullptr;
        return new_head->next;
    }
};
