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
    string serialize(TreeNode* root){
        if(!root){
            return "@";
        }
        return to_string(root->val) + "#" + serialize(root->left) + serialize(root->right);

    }

    vector<int> z_algorithm(string combined){

        int size = combined.size();
        vector<int> ans(size,0);
        int l = 0; 
        int r = 0;

        
        for(int i = 1; i < size; i++){
            if(i <= r){
                ans[i] = min(i - l, ans[i - l]);//-1 is also optional
            }
            while( ans[i] < size && i < size && (combined[ans[i]] == combined[ans[i] + i])){
                ans[i]++;
            }

            if(i + ans[i] > r){
                r = i + ans[i];
                l = i;
            }

        }

        return ans;

    }


        bool isSubtree(TreeNode* root, TreeNode* subRoot) {// to make it very fast we can use z algorithm

        string substr = serialize(subRoot);
        string mainTree = serialize(root);
        string runZ = substr + "/" + mainTree;
        vector<int> ans = z_algorithm(runZ);

        for(int i = substr.size(); i < ans.size(); i++){
            if(ans[i] >= substr.size())return true;
        }
        return false;
    }
};
