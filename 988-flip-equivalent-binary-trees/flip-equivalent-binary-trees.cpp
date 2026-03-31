class Solution {
public:
    // paired or mirror DFS pattern
    bool solve(TreeNode* a, TreeNode* b) {
        if(a == NULL && b == NULL) return true;
        if(a == NULL || b == NULL) return false;
        if(a -> val != b -> val) return false;

        bool no_flip = solve(a -> left, b -> left) && solve(a -> right, b -> right);
        bool flip = solve(a -> left, b -> right) && solve(a -> right, b -> left);

        return flip || no_flip;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};