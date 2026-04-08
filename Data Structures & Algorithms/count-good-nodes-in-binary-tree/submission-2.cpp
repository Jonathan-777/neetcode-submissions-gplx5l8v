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
    int goodNodes(TreeNode* root) {

        TreeNode* temp = root; 
        vector<int> v;
        queue<pair<TreeNode*,int>> q;
        q.push({temp, temp->val});
         int ans = 0;

        while (!q.empty()) {
            TreeNode* curr = q.front().first;
            int max_so_far = q.front().second;
            q.pop();

            // 1. Check if the current node is "good"
            if (curr->val >= max_so_far) {
                ans++;
            }

            // 2. Update the max value for the children's paths
            int next_max = max(max_so_far, curr->val);

            // 3. Push children only if they exist
            if (curr->left) {
                q.push({curr->left, next_max});
            }
            if (curr->right) {
                q.push({curr->right, next_max});
            }
        }

       
        // cout << v.size();

        // for(int i = 0; i < v.size(); i++){
        //     if( 2*i+2 < v.size() && v[i] <= v[2*i+1] && v[i] <= v[i*2 +2]){
        //         ans++;
        //     }else if(2*i+2 < v.size() && v[i] <= v[2*i+1]){
        //         ans++;

        //     }else if(2*i+2 < v.size() &&  v[i] <= v[i*2 +2] ){
        //         ans++;
        //     }

        // }
        return ans;
        
    }
};
