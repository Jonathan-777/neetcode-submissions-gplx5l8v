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
    int kthSmallest(TreeNode* root, int k) {
        int ans = INT_MIN; 
        int counter = 0;
        kthNode(root,ans,k,counter);
        return ans;


        
    }
    void kthNode(TreeNode* root,int& ans,int k, int& counter){
        if(!root){
            return;
        }



        kthNode(root->left, ans,k,counter);

        counter++;
        if(counter == k && root){
            ans =  root->val;
        }
        kthNode(root->right, ans,k,counter);

    }


};
