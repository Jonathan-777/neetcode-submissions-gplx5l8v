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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0; 
        dfs(root , ans);
        return ans;
        
    }

    int dfs(TreeNode* root, int &x){
        if(!root){
            return 0;
        }
        int r = dfs(root->right, x);
        int l = dfs(root->left,x);
        // trick is to calculate while recursion unwinds since we care about path not nodes
        if(x < max(x,r+l)){
            x = max(x,r+l);
        }
        return 1 + max(l,r);
    }
};
