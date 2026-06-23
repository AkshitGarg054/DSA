class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root -> val == p -> val || root -> val == q -> val) return root;

        auto left = lowestCommonAncestor(root -> left, p, q);
        auto right = lowestCommonAncestor(root -> right, p, q);

        if(left && right) return root;
        
        return left ? left : right;
    }
};