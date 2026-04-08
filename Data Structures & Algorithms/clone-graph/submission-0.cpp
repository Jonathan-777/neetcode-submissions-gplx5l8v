/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> oldToNew;// old, new
        queue<Node*> q;

        oldToNew[node] = new Node(node->val);
        q.push(node);// push old

        while(!q.empty()) {
            Node* cur = q.front();// cur is an old instance
            q.pop();

            for (Node* temp : cur->neighbors) {
                if (oldToNew.find(temp) == oldToNew.end()) {// if temp doesnt exists in hashmap already
                    oldToNew[temp] = new Node(temp->val);//
                    q.push(temp);// push all neighbors to q
                }
                oldToNew[cur]->neighbors.push_back(oldToNew[temp]);// to new - add all the copycat nodes emulating old
            }
        }


        return oldToNew[node];
    }
};




