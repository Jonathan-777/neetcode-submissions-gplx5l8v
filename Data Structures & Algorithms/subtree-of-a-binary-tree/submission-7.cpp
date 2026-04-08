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
        if(!root)return "#";

        return to_string(root->val) + "$" + serialize(root->left) + serialize(root->right);
    }

    vector<int> z_algorithm(const string& combined){
        int size = combined.size();
        vector<int> v(size,0); // 02000
        int l = 0;
        int r = 0;

        for(int i = 1; i <size ; i++){
            if(i <= r){
                v[i] = min( r - i + 1, v[i-l]);
            }
            
            while(!v.empty() && i + v[i] < size && (combined[v[i]] == combined[i + v[i]])){
                v[i]++;
            }
            if(i + v[i]  > r){
                l = i;
                r = i + v[i];
            }
        }
        return v;
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
