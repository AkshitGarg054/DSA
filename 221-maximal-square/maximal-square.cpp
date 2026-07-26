class Solution {
public:
    int n, m;
    int dp[301][301];

    int solve(int i, int j, vector<vector<char>> &grid) {
        if(grid[i][j] == '0') return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1; // the cell itself
        if(i > 0 && j > 0 && grid[i - 1][j] == '1' && grid[i][j - 1] == '1' && grid[i - 1][j - 1] == '1') {
            ans = 1 + min({solve(i - 1, j, grid), solve(i, j - 1, grid), solve(i - 1, j - 1, grid)});
        }

        return dp[i][j] = ans;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        memset(dp, -1, sizeof(dp));

        int maxi = INT_MIN;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    int len = solve(i, j, matrix);
                    maxi = max(maxi, len);
                }
            }
        }

        return 1LL * maxi * maxi;
    }
};