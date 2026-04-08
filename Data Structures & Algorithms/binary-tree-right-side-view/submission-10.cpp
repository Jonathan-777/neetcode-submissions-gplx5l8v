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
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        ans.clear();
        int h = 0;
        int curr = 0;
        rightSideView_helper(root,h,curr);
        return ans;
        
    }

    void rightSideView_helper(TreeNode* root, int &h, int curr){
        if(!root){
            return;
        }

        if(curr >= h){
            ans.push_back(root->val);
            h++;
        }
        curr++;
        rightSideView_helper(root->right, h, curr);
        rightSideView_helper(root->left, h , curr);



    }
};
