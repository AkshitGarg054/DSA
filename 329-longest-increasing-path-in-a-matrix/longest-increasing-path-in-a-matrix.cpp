class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dp[201][201];

    // visited is not needed because we always move towards a strictly larger value (so there is no point of taking the back step again).
    int solve(int i, int j, vector<vector<int>> &grid) {
        if(dp[i][j] != -1) return dp[i][j];
        int len = 1;

        for(auto &d: dirs) {
            int ni = i + d[0];
            int nj = j + d[1];

            if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if(grid[i][j] >= grid[ni][nj]) continue;

            len = max(len, 1 + solve(ni, nj, grid));
        }

        return dp[i][j] = len;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        int maxi = INT_MIN;
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int temp = solve(i, j, matrix);
                maxi = max(maxi, temp);
            }
        }

        return maxi;
    }
};