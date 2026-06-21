class Solution {
public:
    // best template
    int solve(TreeNode* root) {
        if(root == NULL) return 0;

        int left = 1 + solve(root -> left);
        int right = 1 + solve(root -> right);

        return max(left, right);
    }

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return solve(root);
    }
};