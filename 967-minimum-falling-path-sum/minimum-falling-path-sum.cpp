class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& matrix) {
        if(j < 0 || j >= m) return 1e9;
        if(i == n - 1) return matrix[i][j];
        if(i >= n) return 0;
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int left = matrix[i][j] + solve(i + 1, j - 1, matrix);
        int bottom = matrix[i][j] + solve(i + 1, j, matrix);
        int right = matrix[i][j] + solve(i + 1, j + 1, matrix);

        return dp[i][j] = min({left, bottom, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp.resize(n, vector<int>(m, INT_MAX));

        int mini = INT_MAX;
        for(int j = 0; j < m; j++) {
            mini = min(mini, solve(0, j, matrix));
        }

        return mini;
    }
};