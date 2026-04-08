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
    int h = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        h = 0;
     diameterOfBinaryTree_helper( root);
        return h;
    }

    auto diameterOfBinaryTree_helper(TreeNode* root )->int{
        if(!root){
            return -1;
        }

        int l = diameterOfBinaryTree_helper(root->left ) + 1;
        int r = diameterOfBinaryTree_helper(root->right) + 1;
        if( h < l + r){
            h = l+r;
        }

        return ( l > r)? l: r;



    }
};
