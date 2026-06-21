class Solution {
public:
    int ans = INT_MIN;

    int solve(TreeNode* root) {
        if(root == NULL) return 0;

        int left = 1 + solve(root -> left);
        int right = 1 + solve(root -> right);

        ans = max(ans, left + right);

        return max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        solve(root);
        return ans - 2;
    }
};