class Solution {
public:
    int maxSum = INT_MIN;

    int solve(TreeNode* node) {
        if (node == NULL) return 0;

        int left = solve(node->left);
        int right = solve(node->right);

        maxSum = max(maxSum, left + right + node->val);

        return max(0, node->val + max(left, right));
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};