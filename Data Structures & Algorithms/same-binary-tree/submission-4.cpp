class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both are null, they are identical up to this point
        if (!p && !q) return true;
        
        // If only ONE is null (because the previous check failed), they don't match
        if (!p || !q) return false;
        
        // If values don't match, fail fast
        if (p->val != q->val) return false;
        
        // Check the rest of the subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};