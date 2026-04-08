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
    vector<int> rightSideView(TreeNode* root) {
         vector<int> ans;
        getRightSideNodes(ans,root);
        return ans;
        
    }

    void getRightSideNodes(vector<int>& ans,TreeNode* root,int level =0){
        if(!root){
            return;
        }
        if(ans.size() == level){
        ans.push_back(root->val);
        }

        getRightSideNodes(ans,root->right,level+1);
        getRightSideNodes(ans,root->left, level+1);
        
    }
};
