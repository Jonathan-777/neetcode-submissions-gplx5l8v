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
    bool isValidBST(TreeNode* root) {

        return isValidBST_helper(root,INT_MAX,INT_MIN);
        
    }

    bool isValidBST_helper(TreeNode* root, int biggestAllowed, int smallestAllowed){
        if(!root){
            return true;
        }
        if(root->val <= smallestAllowed){
            return false;
        }
        if(root->val >= biggestAllowed){
            return false;
        }
        int childMax = max(biggestAllowed, root->val);
        int childMin = min(smallestAllowed, root->val);

        bool r = isValidBST_helper(root->right, biggestAllowed, root->val);
        bool l = isValidBST_helper(root->left, root->val,smallestAllowed);

        
        return (l && r);
    }
};
