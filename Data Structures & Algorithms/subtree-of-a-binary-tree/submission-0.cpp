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

        vector<int> z_function(string s) {
            int n = s.length();
            vector<int> vec(n); // vec[i] stores the length of the LCP between s and s[i..n-1]
            
            // [l, r] maintains the "Z-box": the interval with the largest 'r' 
            // such that s[l..r] is a prefix of s.
            int l = 0, r = 0; 
            
            for (int i = 1; i < n; i++) {
                // Step 1: Use previously computed values if i is within the current Z-box
                if (i <= r) {
                    // We can initialize vec[i] to the value at the corresponding position 
                    // in the prefix (vec[i-l]), but we must cap it at the boundary (r-i+1).
                    vec[i] = min(r - i + 1, vec[i - l]);
                }

                // Step 2: Attempt to extend the match beyond the Z-box using naive comparison
                while (i + vec[i] < n && s[vec[i]] == s[i + vec[i]]) {
                    vec[i]++;
                }
                
                // Step 3: If we found a match that extends past the current 'r', 
                // update the Z-box boundaries.
                if (i + vec[i] - 1 > r) {
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

        vector<int> z_values = z_function(combined);
        int sub_len = serialized_subRoot.length();

        for (int i = sub_len + 1; i < combined.length(); i++) {
            if (z_values[i] == sub_len) {
                return true;
            }
        }
        return false;
    }
};