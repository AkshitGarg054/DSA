class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root -> val == p -> val || root -> val == q -> val) return root;

        TreeNode* left = solve(root -> left, p, q);
        TreeNode* right = solve(root -> right, p, q);

        if(left && right) return root;

        return left ? left : right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        return solve(root, p, q);
    }
};