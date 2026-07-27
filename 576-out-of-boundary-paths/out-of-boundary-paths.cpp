class Solution {
public:
    const int MOD = 1e9 + 7;
    int n, m;
    int dp[51][51][51];

    int solve(int i, int j, int k) {
        if(k < 0) return 0;
        if((i < 0 || i >= n || j < 0 || j >= m)) return 1; 
        if(dp[i][j][k] != -1) return dp[i][j][k];

        long long up = solve(i - 1, j, k - 1);
        long long down = solve(i + 1, j, k - 1);
        long long left = solve(i, j - 1, k - 1);
        long long right = solve(i, j + 1, k - 1);

        return dp[i][j][k] = (up + down + left + right) % MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this -> n = m; // NOTE: remember to interchange
        this -> m = n;

        memset(dp, -1, sizeof(dp));
        return solve(startRow, startColumn, maxMove);
    }
};