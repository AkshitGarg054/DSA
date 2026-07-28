class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dp[201][201];

    // visited is not needed because we always move towards a strictly larger value (so there is no point of taking the back step again).
    int solve(int i, int j, vector<vector<int>> &grid) {
        if(i < 0 || i >= n || j < 0 || j >= m) return -1e9;
        if(dp[i][j] != -1) return dp[i][j];

        int len = 1;
        if(i + 1 < n && grid[i + 1][j] > grid[i][j]) len = max(len, 1 + solve(i + 1, j, grid)); // down
        if(i > 0 && grid[i - 1][j] > grid[i][j]) len = max(len, 1 + solve(i - 1, j, grid)); // up
        if(j + 1 < m && grid[i][j + 1] > grid[i][j]) len = max(len, 1 + solve(i, j + 1, grid)); // right
        if(j > 0 && grid[i][j - 1] > grid[i][j]) len = max(len, 1 + solve(i, j - 1, grid)); // left

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