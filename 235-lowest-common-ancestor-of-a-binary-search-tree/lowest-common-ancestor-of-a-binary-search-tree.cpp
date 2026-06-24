class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root -> val == p -> val || root -> val == q -> val) return root;

        auto left = lca(root -> left, p, q);
        auto right = lca(root -> right, p, q);

        if(left && right) return root;
        return left ? left : right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        return lca(root, p, q);
    }
};