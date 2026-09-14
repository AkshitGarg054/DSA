class Solution {
public:
    int solve(TreeNode* root) {
        if(root == NULL) return 0;

        int left = solve(root -> left);
        int right = solve(root -> right);

        if(abs(left - right) <= 1) return max(left, right) + 1;
        return 1e9;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(root -> left == NULL && root -> right == NULL) return true;

        int ans = solve(root);
        if(ans >= 1e9) return false;
        return true;
    }
};