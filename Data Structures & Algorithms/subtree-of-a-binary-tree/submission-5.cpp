/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Added a '^' prefix to prevent partial matches (e.g., finding "2" inside "12")
    string serialize(TreeNode* root) {
        if (!root) {
            return "#";
        }
        return "^" + to_string(root->val) + "$" + serialize(root->left) + serialize(root->right);
    }

    bool rabin_karp(const string& pattern, const string& text) {
        int m = pattern.length();
        int n = text.length();

        // Edge cases
        if (m == 0) return true;
        if (m > n) return false;

        const int d = 256;          // Alphabet size
        const int q = 1000000007;   // Large prime for modulo

        long long p_hash = 0;
        long long t_hash = 0;
        long long h = 1;

        // Precompute the multiplier for the highest order character
        for (int i = 0; i < m - 1; i++) {
            h = (h * d) % q;
        }

        // Calculate initial hashes for the pattern and the first window of text
        for (int i = 0; i < m; i++) {
            p_hash = (d * p_hash + pattern[i]) % q;
            t_hash = (d * t_hash + text[i]) % q;
        }

        // Slide the window
        for (int i = 0; i <= n - m; i++) {
            // If hashes match, verify the actual string to rule out collisions
            if (p_hash == t_hash) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }
                // Early exit! We found the subtree, no need to keep searching.
                if (match) return true; 
            }

            // Roll the hash forward to the next window
            if (i < n - m) {
                t_hash = (d * (t_hash - text[i] * h) + text[i + m]) % q;
                if (t_hash < 0) {
                    t_hash = (t_hash + q);
                }
            }
        }

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // We serialize both trees and check if subRoot's string is a substring of root's string
        string pattern = serialize(subRoot);
        string text = serialize(root);
        
        return rabin_karp(pattern, text);
    }
};