/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = new Node(0);
        Node* temp = newHead;
        Node* temp_2 = head;

        while(temp_2){
            temp->next = new Node(temp_2->val);
            temp = temp->next;  // move to the new item created
            
            temp->random = temp_2->random;// our new item will hold the node that matches its random counterpart in og list (held in random ptr)
           
            temp_2->random = temp; // each node from the og list will hold their counterpart in the random field
            temp_2 = temp_2->next; // move og list
        }
        temp->next = nullptr;
        temp_2 = head;
        temp = newHead->next;

        while(temp){
            if(temp->random){
                temp->random = temp->random->random;
            }
            temp = temp->next;
        }
        return newHead->next;
    }
};
