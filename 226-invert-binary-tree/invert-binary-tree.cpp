class Solution {
public:
    TreeNode* solve(TreeNode* root) {
        if(root == NULL) return NULL;
        
        auto left_subtree = solve(root -> left);
        auto right_subtree = solve(root -> right);

        root -> left = right_subtree;
        root -> right = left_subtree;

        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;

        solve(root);
        return root;
    }
};