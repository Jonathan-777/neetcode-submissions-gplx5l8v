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
        return heightOrFail(root) != -1;
    }

    int heightOrFail(TreeNode* node) {
        if (!node) return 0;

        int lh = heightOrFail(node->left);
        if (lh == -1) return -1;

        int rh = heightOrFail(node->right);
        if (rh == -1) return -1;

        if (std::abs(lh - rh) > 1) return -1;

        return 1 + std::max(lh, rh);
    }

};
