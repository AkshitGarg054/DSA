class Solution {
public:
    int ans = INT_MIN;

    int solve(TreeNode* root) {
        if(root == NULL) return 0;

        int left = (root -> val) + solve(root -> left);
        int right = (root -> val) + solve(root -> right);

        // if the subtree's contribution was negative
        // then its better to just take the root -> val
        left = max(left, root -> val);
        right = max(right, root -> val);

        ans = max(ans, left + right - (root -> val));

        return max(left, right); 
    }

    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        solve(root);
        return ans;
    }
};