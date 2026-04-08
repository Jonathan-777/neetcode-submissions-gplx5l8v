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

class Solution {  //
public:
    TreeNode* ans = nullptr;
    int kthSmallest(TreeNode* root, int k) {
        ans = nullptr;
        int temp = k;
        kthSmallest_helper(root,temp);
        return ans->val;
        
    }

    void kthSmallest_helper(TreeNode* root, int& temp){
        if(!root || temp < 0){
            return;
        }
        
        
        
        kthSmallest_helper(root->left, temp);
        temp--;
        
        if(temp == 0){
            
                ans = root;
            
            return;
        }
        kthSmallest_helper(root->right,temp);
    }
};
