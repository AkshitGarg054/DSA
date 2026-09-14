class Solution {
public:
    int solve(TreeNode* root) {
        if(root == NULL) return 0;

        int left = solve(root -> left);
        int right = solve(root -> right);

        return max(left, right) + 1;
    }

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int ans = solve(root);
        return ans;
    }
};