class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));

        auto getCost = [&](int x) {
            if(x == 0) return 0;
            return 1;
        };

        int c0 = getCost(grid[0][0]);
        if(c0 <= k) dp[0][0][c0] = grid[0][0];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int c = 0; c <= k; c++) {
                    if(dp[i][j][c] == -1) continue;

                    if(j + 1 < m) {
                        int nc = c + getCost(grid[i][j + 1]);
                        if(nc <= k) dp[i][j + 1][nc] = max(dp[i][j + 1][nc], dp[i][j][c] + grid[i][j + 1]);
                    }

                    if(i + 1 < n) {
                        int nc = c + getCost(grid[i + 1][j]);
                        if(nc <= k) dp[i + 1][j][nc] = max(dp[i + 1][j][nc], dp[i][j][c] + grid[i + 1][j]);
                    }
               }
            }
        }

        int ans = -1;
        for(int c = 0; c <= k; c++) ans = max(ans, dp[n-1][m-1][c]);

        return ans;
    }
};