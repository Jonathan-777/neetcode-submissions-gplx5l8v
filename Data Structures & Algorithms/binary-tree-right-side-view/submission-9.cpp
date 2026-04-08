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
        cout << (int)ans.size()-1 << endl;
        hello(root,ans);
        return ans;
        
    }

    void hello(TreeNode* root, vector<int> &ans, int level = 0){
        if(!root){
            return;
        }

        if((int)ans.size()-1 < level){
            ans.push_back(root->val);

        }


            hello(root->right, ans, level+1);
            hello(root->left, ans, level+1);
        

    }


};
