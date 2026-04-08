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
    struct pq_helper{
        bool operator() (int a, int b){
          return  a > b;
        }
    };
        priority_queue<int, vector<int>, pq_helper> pq;

    int kthSmallest(TreeNode* root, int k) {

        int ans = INT_MIN;
        kthSmallest_helper(root);
        while(k > 1){
            cout << pq.top();
            pq.pop();
            k--;
        }
        ans =  pq.top();
        return ans;
    }
    
    void kthSmallest_helper(TreeNode* root){
        if(!root){
            return;
        }
        pq.push(root->val);
        kthSmallest_helper(root->left);
        kthSmallest_helper(root->right);
    }
};
