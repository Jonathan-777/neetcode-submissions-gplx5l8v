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
        int h = 0;
        checkDiameter(root,ans,h);
        return ans;
        
    }

    void checkDiameter(TreeNode* root, int& ans,int & h){
        if(!root){
            return ;
        }

        int l =0;
        int r =0;
        checkDiameter(root->left,ans, l);
        checkDiameter(root->right,ans,r);
            

        ans = max(ans, l+r);
        h = 1+max( l , r);
    }
};
