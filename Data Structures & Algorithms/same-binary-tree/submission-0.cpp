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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }
        if((!p && q) || (!q && p) ){// second check can also work if we just check one of the two nodes is ! since the first case accounts for the true case
            return false;
        }
        if(p->val != q->val)return false;

        return isSameTree(p->left,q->left) &&
        isSameTree(p->right,q->right);
        


        
    }
};
