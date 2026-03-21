class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];

        int ans = 0;
        // consider i as root node
        for(int i = 1; i <= n; i++) {
            ans += solve(i - 1, dp) * solve(n - i, dp); // (i-1) nodes before i, (n-i) nodes after i
        }

        return dp[n] = ans;
    }

    int solveTab(int n) { // Tabulation code
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1; // base case

        // two parameters are changing --> number of nodes, and root node 
        for(int i = 2; i <= n; i++) { // i -> number of nodes
            for(int j = 1; j <= i; j++) { // j -> root node
                dp[i] += dp[j - 1] * dp[i - j]; // (j-1) nodes before j, (i-j) nodes after j
            }
        }

        return dp[n];
    }

    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        // return solve(n, dp);
        return solveTab(n);
    }
};