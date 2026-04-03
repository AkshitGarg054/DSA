class Solution {
public:
    const int MOD = 1e9 + 7;
    long long tot_sum = 0;
    long long maxi = 1;

    long long getTotalSum(TreeNode* root) {
        if(root == NULL) return 0;
        return getTotalSum(root -> left) + getTotalSum(root -> right) + (root -> val);
    }

    long long dfs(TreeNode* root) {
        if(root == NULL) return 0;

        long long left = dfs(root -> left);
        long long right = dfs(root -> right);
        long long subSum = left + right + (root -> val);
        maxi = max(maxi, subSum * (tot_sum - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        tot_sum = getTotalSum(root);
        dfs(root);
        return maxi % MOD;
    }
};