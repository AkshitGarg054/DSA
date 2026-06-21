class Solution {
public:
    int ans = INT_MIN;

    int solve(TreeNode* root, int x) {
        if(root == NULL) return -1e9;

        int left = solve(root -> left, x);
        int right = solve(root -> right, x);

        return max({left, right, abs(root -> val - x)});
    }

    void solve_node(TreeNode* root) {
        if(root == NULL) return;

        ans = max(ans, solve(root, root -> val));
        solve_node(root -> left);
        solve_node(root -> right);
    }

    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL) return 0;

        solve_node(root);
        return ans;
    }
};