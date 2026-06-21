class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return NULL;
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};