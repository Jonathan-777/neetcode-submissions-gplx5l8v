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
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "$#";
        }
        return "$" + to_string(root->val) +
                serialize(root->left) + serialize(root->right);
    }

    vector<int> z_function(string s, int substrLen) {
        vector<int> vec(s.length());
        int l = 0, r = 0, n = s.length();


        for (int i = 1; i < n - (substrLen-1); i++) {
            if (i <= r) {
                vec[i] = min( r - i + 1 ,    vec[i - l]  );// special case for when the i is in the window min(ithPlaceInWindowrange , ithPlaceinPrefixRelativeToWindow)
                 cout << "\t which is smaller? " << r - i + 1  << " or " << vec[i-l]<< endl;
            }
                                                                       
            while (i + vec[i] < n && s[vec[i]] == s[i + vec[i]]) {// compare window vs prefix
                vec[i]++;
            }
            // cout << "index " << i << " and vec value  is : " << vec[i] << " and char is : "<< s[i] <<  endl;
            
            if (i + vec[i] - 1 > r) {// update window
                l = i;
                r = i + vec[i] - 1;
            }
        }
        return vec;
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string serialized_root = serialize(root);
        string serialized_subRoot = serialize(subRoot);
        string combined = serialized_subRoot + "|" + serialized_root;
        

        vector<int> z_values = z_function(combined, serialized_subRoot.size());
        int sub_len = serialized_subRoot.length();

        

        for (int i = sub_len + 1; i < combined.length(); i++) {
            if (z_values[i] == sub_len) {
                return true;
            }
        }
        return false;
    }
};









