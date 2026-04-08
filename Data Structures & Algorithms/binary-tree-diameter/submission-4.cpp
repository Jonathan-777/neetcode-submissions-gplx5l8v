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
        int x = 0;
        getDiameter(root,x,ans);
        return ans;

    }
    void getDiameter(TreeNode* root, int& h, int& ans){
        if(!root){
            return;
        }
        int l =0;
        int r = 0;

        getDiameter(root->left, l, ans);
        getDiameter(root->right,r,ans);

        ans = max(ans, l+r);
        // calculating h afterwards ensures that we dont count unwanted nodes
        h = 1 + max(l,r);
        
    }
};
