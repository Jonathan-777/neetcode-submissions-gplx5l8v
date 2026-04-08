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
    int ans = INT_MIN;
    int goodNodes(TreeNode* root) {
        ans = 0;
        int temp = INT_MIN;
        checkNodes(root, temp);
        return ans;
    }

    void checkNodes(TreeNode* root, int& biggest){
        if(!root){
            return;
        }
        int temp = max(root->val, biggest);

        checkNodes(root->left, temp);
        checkNodes(root->right,temp);

        

        if(root->val >= biggest){
            ans++;
        }


    }
};
