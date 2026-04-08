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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> ans;
        TreeNode* temp = root;
        queue<TreeNode*> q;
        q.push(root);
        int l =  0;

        while(!q.empty()){
            int level_size = q.size();
            temp = q.front();
            ans.push_back(  vector<int>() );
            for(int i = 0; i < level_size; i++){
                ans[l].push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                q.pop();
                temp = q.front();
            }
            l++;
        }

        return ans;
        
    }
};
