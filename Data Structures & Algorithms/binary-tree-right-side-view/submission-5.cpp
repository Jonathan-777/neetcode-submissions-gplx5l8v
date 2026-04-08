class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; // No 'static' here! Fresh for every call.
        getRightSideNodes(ans, root, 0);
        return ans;
    }

    void getRightSideNodes(vector<int>& ans, TreeNode* root, int level) {
        if (!root) return;

        // Logic fix: Only add the node if we are visiting this level for the first time
        if (level == ans.size()) {
            ans.push_back(root->val);
        }

        // Visit Right first, then Left
        getRightSideNodes(ans, root->right, level + 1);
        getRightSideNodes(ans, root->left, level + 1);
    }
};