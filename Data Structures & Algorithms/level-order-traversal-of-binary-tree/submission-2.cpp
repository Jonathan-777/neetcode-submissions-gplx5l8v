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
        if(!root){
            return {};
        }

        TreeNode* temp = root;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        int z = 0;

        while(!q.empty()){
            int size = q.size();
            ans.push_back({});

            for(int i = 0; i < size; i++){
                ans[z].push_back(q.front()->val);
                temp = q.front();

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }

                q.pop();
                
            }
            z++;

        }
        return ans;
    }
};
