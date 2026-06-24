class Solution {
public:
    // condition: left_max < root->val < right_min

    struct Info {
        long long mini;
        long long maxi;
        int sum;
        bool isBST;
    };

    int ans = 0;

    Info solve(TreeNode* root) {
        if(root == NULL) return {LLONG_MAX, LLONG_MIN, 0, true};

        auto left = solve(root -> left);
        auto right = solve(root -> right);

        if(left.isBST && right.isBST && (left.maxi < root -> val && right.mini > root -> val)) {
            int new_mini = min(left.mini, (long long)root -> val);
            int new_maxi = max(right.maxi, (long long)root -> val);
            int sum = left.sum + right.sum + root -> val;

            ans = max(ans, sum);
            return {new_mini, new_maxi, sum, true};
        }

        return {LLONG_MIN, LLONG_MAX, 0, false};
    }

    int maxSumBST(TreeNode* root) {
        if(root == NULL) return 0;
        solve(root);
        return ans;
    }
};