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
    bool validate(TreeNode* node, long minVal, long maxVal) {
            if (node == nullptr) return true;

            // If the current node's value breaks the range constraints, it's invalid
            if (node->val <= minVal || node->val >= maxVal) return false;

            // Recursively check subtrees with updated ranges
            // Left child must be < node->val
            // Right child must be > node->val
            return validate(node->left, minVal, node->val) && 
                validate(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};
