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
    int inorder_count = 0;
    int preorder_count = 0;
   TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int limit) {
        if (preorder_count >= preorder.size()) return nullptr;
        if(inorder[inorder_count] == limit){
            inorder_count++;
            return nullptr;
        }

        TreeNode* temp = new TreeNode(preorder[preorder_count++]);

        temp->left = dfs(preorder,inorder, temp->val);
        temp->right = dfs(preorder,inorder,limit);
        return temp;

   }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

              return dfs(preorder, inorder, INT_MAX);

        
    }



};
