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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSum_helper(root, ans);
        return (ans == INT_MIN)? root->val : ans;

    }

    int maxPathSum_helper(TreeNode* root, int& max_val){
        if(!root){
            return -2000;
        }

        int l = maxPathSum_helper(root->left , max_val);
        int r = maxPathSum_helper(root->right,max_val);

        if(l == -2000 && r == -2000){
            
            if(max_val < root->val){
                max_val = root->val;
            }
            return root->val;
        }
        int local_max = root->val; 
        
        if (l != -2000) {
            local_max = max(local_max, l + root->val);
        }
        if (r != -2000) {
            local_max = max(local_max, r + root->val);
        }
        if (l != -2000 && r != -2000) {
            local_max = max(local_max, l + r + root->val);
        }

        // Now that we found the true maximum combination for this node, update global max
        if (local_max > max_val) {
            max_val = local_max;
        }

        int biggest = 0;

        if(l != -2000 && r != -2000){
            biggest = max(l,r);
        }else if(l != -2000 ){
            biggest = l;
        }else{
            biggest = r;
        }
        biggest = max(0,biggest);

         return root->val + biggest;
    }
};
