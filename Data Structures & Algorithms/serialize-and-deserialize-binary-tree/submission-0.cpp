/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "#";
        }
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp = "";
        stringstream ss(data);

        while(getline(ss,temp,',')){
            q.push(temp);
        }
        return buildTree(q);
    }

    TreeNode* buildTree(queue<string>& q){
        string curr = q.front();
        q.pop();
        if(curr == "#"){
            return nullptr;
        }
        TreeNode* temp = new TreeNode(stoi(curr));

        temp->left = buildTree(q);
        temp->right = buildTree(q);
        return temp;
    }
};
