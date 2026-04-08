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
 #pragma GCC optimize("O3")
 auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }

        int l = 1 +  maxDepth(root->left);
        int r = 1 + maxDepth(root->right);

        return (l >= r) ? l : r;
        
    }
};
