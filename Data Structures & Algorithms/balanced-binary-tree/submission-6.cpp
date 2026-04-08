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
        bool diff = true;
        isBalanced_helper(root,diff);
        return diff;
        
    }
    auto isBalanced_helper(TreeNode* root, bool& diff)->int{
        if(!root){
            return 0;
        }
        
        int l = isBalanced_helper(root->left, diff) ;
        int r = isBalanced_helper(root->right, diff) ;

        if( 1 < abs(l-r)){
            diff = false;
        }
        
        return (l < r)? ++r : ++l;

    }
};
