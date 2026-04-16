class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>> &grid) {
        if(i >= n || j >= m) return 0;
        if(i == n-1 && j == m-1) return 1;
        if(grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j + 1, grid);
        int down = solve(i + 1, j, grid);

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) return 0;

        dp.assign(n, vector<int>(m, -1));
        return solve(0, 0, obstacleGrid);
    }
};