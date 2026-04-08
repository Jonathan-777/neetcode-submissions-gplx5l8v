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
        int ans = 0;
        checkBalance(root,ans);
        return (ans > 1)? false : true;

        
    }
    int checkBalance(TreeNode* root, int &sentinel){
        if(!root){
            return 0;
        }
        int l = checkBalance(root->left, sentinel);
        // if(l > 1){sentinel = INT_MAX;}
        int r = checkBalance(root->right, sentinel);
        // if(r > 1){sentinel = INT_MAX;}

         if(1 < abs(l - r)){
            sentinel = INT_MAX;
         }

         return 1 + max(l,r);


    }


};
