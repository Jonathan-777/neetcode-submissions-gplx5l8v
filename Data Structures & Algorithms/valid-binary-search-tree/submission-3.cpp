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
        return isValidBST_Helper(root, INT_MAX, INT_MIN);
        
    }
    bool isValidBST_Helper(TreeNode* root, int biggest, int smallest){
        if(!root){
            return true;
        }
                if(biggest <= root->val || smallest >= root->val){
                    return false;
                }
        bool l = isValidBST_Helper(root->left, root->val, smallest);
        bool r = isValidBST_Helper(root->right, biggest, root->val);
        return (l && r);
    }
};
