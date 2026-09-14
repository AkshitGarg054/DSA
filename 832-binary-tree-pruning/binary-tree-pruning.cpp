class Solution {
public:
    // We are checking if the subtree contains any 1 or not.
    int solve(TreeNode* root) {
        if(root == NULL) return 0;

        int left = solve(root -> left);
        int right = solve(root -> right);

        if(left == 0) root -> left = 0;
        if(right == 0) root -> right = 0;

        return left | right | root -> val;
    }

    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return NULL;

        solve(root);
        if(root -> val == 0 && root -> left == NULL && root -> right == NULL) return NULL;
        return root;
    }
};