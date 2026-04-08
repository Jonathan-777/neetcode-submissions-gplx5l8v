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
            return 0;
        }

        int l = max(0, maxPathSum_helper(root->left, max_val));
        int r = max(0, maxPathSum_helper(root->right, max_val));

        int path_sum = root->val + l + r;

        max_val = max(path_sum, max_val);

        return root->val + max(l,r);
    }
};
