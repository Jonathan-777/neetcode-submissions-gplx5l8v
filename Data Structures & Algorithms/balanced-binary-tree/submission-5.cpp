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
        int temp = 0;
        balanceAnalysis(root, ans,temp);
        return ans;
        
    }

    void balanceAnalysis(TreeNode* root, bool& ans, int& h){
        if(!root){
            return ;
        }
        int r = 0;
        int l = 0;
        balanceAnalysis(root->left, ans, l);
        balanceAnalysis(root->right,ans,r);


        if(abs(l - r) > 1){
            ans = false;
        }
        h =1 + max(l,r);
    }
};
