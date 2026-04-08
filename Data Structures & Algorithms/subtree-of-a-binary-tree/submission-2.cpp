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
            return "$#";
        }
        return to_string(root->val) + "$" + serialize(root->left) + serialize(root->right);

    }

    vector<int> zAlgorithm(string s, int substrSIZE){
        
        int size = s.size();
        int l = 0; 
        int r = 0;
        vector<int> v(size,0);

         

        for(int i = 0; i < size; i++){
            //skip uneeded checks
            if(r >= i){
                r = min(r-i, v[i-l+1]);
            }

            // calculate window
            while((size > i && substrSIZE > v[i] ) && s[v[i]] == s[i + v[i]]  ){
                v[i]++;
            }

            // update l and r
            if(r < i + v[i]-1){
                r = i + v[i]-1;
                l = i;
            }
        }

        return v;
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // we turn an easy problem into a hard one by finding a robust solution (z algorithm)
        string substr = serialize(subRoot);
        string mainTree = serialize(root);
        string runZ = substr + "/" + mainTree;
        vector<int> ans = zAlgorithm(runZ, substr.size());

        for(int i = substr.size(); i < ans.size(); i++){
            if(ans[i] == substr.size()){
                return true;
            }
        }

        return false;
    }
};





















