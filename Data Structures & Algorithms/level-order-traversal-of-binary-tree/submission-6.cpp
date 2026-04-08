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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)return {};
        queue<TreeNode*> s;
        vector<vector<int>> v;
        s.push(root);
        TreeNode* temp = s.front();


        while(!s.empty()){
            
            int size = s.size();
            vector<int> sentinel;
            for(int i = 0; i < size; i++){
                temp = s.front();
                sentinel.push_back(temp->val);
                if(temp->left)s.push(temp->left);
                if(temp->right)s.push(temp->right);
                s.pop();
                
            }
            v.push_back(sentinel);
        }
        return v;
    }
};
