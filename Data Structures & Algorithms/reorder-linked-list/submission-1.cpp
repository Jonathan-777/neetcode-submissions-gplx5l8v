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
        // pair where one is the new index and the second is the listnode
        vector<pair<int,ListNode*>> pairs;
        ListNode* temp = head;
        int counter = 0;
        while(temp){
            pairs.push_back({counter,temp});
            counter++;
            temp = temp->next;
        }
        counter++;// ammount of items(not indexed)

        ListNode* tempHead = new ListNode(0);
        temp = tempHead;
        bool takeTurn = true;
        auto leftIt = pairs.begin();
        auto rightIt = pairs.end()-1;


        while(leftIt <= rightIt){
            
            if(takeTurn){

                temp->next = leftIt->second;
                leftIt++;
                takeTurn= false;
                
            }else{
                auto it = pairs.end()-1;
                temp->next = rightIt->second;
                rightIt--;
                takeTurn= true;
                
            }
            temp = temp->next;

        }
        pairs.clear();
        temp->next = nullptr;
        head = tempHead->next;
    }
};
