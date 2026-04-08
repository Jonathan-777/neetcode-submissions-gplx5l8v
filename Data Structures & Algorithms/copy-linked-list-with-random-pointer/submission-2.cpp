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
    Node* copyRandomList(Node* head) {// handle nullptr
        Node* new_list = new Node(0);
        Node* temp = new_list;

        Node* head_temp = head;

        while(head_temp){
            temp->next = new Node(head_temp->val);
            temp = temp->next;
            temp->random = head_temp->random;
            head_temp->random = temp;   
            head_temp = head_temp->next;         
        }
        temp->next = nullptr;

        temp = new_list->next;
        head_temp = head;

        while(temp){
            if(temp->random){
                temp->random = temp->random->random;
            }
            temp = temp->next;
            head_temp = head_temp->next;
        }
        return new_list->next;
        
    }
};
