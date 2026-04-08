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
    int ans = 0;
    int goodNodes(TreeNode* root) {
        ans = 0;
        goodNodes_helper(root, INT_MIN);
        return ans;
    }

    void goodNodes_helper(TreeNode* root, int biggestSoFar){
        if(!root){
            return;
        }
        if(biggestSoFar <= root->val){
            ans++;
            biggestSoFar = root->val;
        }
        goodNodes_helper(root->right, biggestSoFar);
        goodNodes_helper(root->left, biggestSoFar);
        return;
    }
};
