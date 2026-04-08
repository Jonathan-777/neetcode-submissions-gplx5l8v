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
        vector<pair<int,ListNode*>> pairs;
        ListNode* temp = head;
        int counter = 0;
        while(temp){
            pairs.push_back({counter,temp});
            counter++;
            temp = temp->next;
        }
        // auto it = find_if(pairs.begin(),pairs.end(), [&n](const auto & x){      // will find n, not nth from end
        //     return x.first == n;
        // });
        int forward_index = (pairs.size() - n);
        ListNode* tempHead = new ListNode(0);
        temp = tempHead;
        

        for(int i = 0; i < pairs.size(); i++){
            if(i == forward_index){
                continue;
            }else{
                temp->next = pairs[i].second;
                temp = temp->next;
            }
        }
        temp->next = nullptr;
        return tempHead->next;
        
    }
};
