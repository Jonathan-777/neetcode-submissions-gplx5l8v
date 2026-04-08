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
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int h = 0;
        checkBalance(root,ans,h);
        return ans;
        
    }
    void checkBalance(TreeNode*root , bool &ans, int& h){
        if(!root){
            return;
        }
        int l = 0; 
        int r = 0;
        checkBalance(root->left, ans, l);
        checkBalance(root->right,ans, r);

        if(abs(l - r) > 1){
             ans = false;
        }

        h = 1 + max(l,r);

    }


};
