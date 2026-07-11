class Solution {
public:
    // our solve function depends on two things: root and prev
    // so we need to store two values per node. (prev and answer)
    unordered_map<TreeNode*, vector<int>> dp; 

    int solve(TreeNode* root, bool prev) {
        if(root == NULL) return 0;
        if(dp.count(root) && dp[root][prev] != -1) return dp[root][prev];
        if(!dp.count(root)) dp[root] = {-1, -1}; // answers for prev = 0 and prev = 1

        int ans = INT_MIN;

        if(prev == true) { // prev node was robbed
            return solve(root -> left, false) + solve(root -> right, false); // get the results from left and right subtree
        }
        else {
            int take = root -> val + solve(root -> left, true) + solve(root -> right, true);
            int skip = solve(root -> left, false) + solve(root -> right, false);
            ans = max(take, skip);
        }

        return dp[root][prev] = ans;
    }

    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        
        int ans = solve(root, false); // true -> robbed previously
        return ans;
    }
};