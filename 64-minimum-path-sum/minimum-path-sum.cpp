class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    
    int solve(int row, int col, vector<vector<int>> &grid) {
        if(row >= n || col >= m) return 1e9;
        if(row == n-1 && col == m-1) return grid[row][col];
        if(dp[row][col] != -1) return dp[row][col];

        int down = grid[row][col] + solve(row + 1, col, grid);
        int right = grid[row][col] + solve(row, col + 1, grid);

        return dp[row][col] = min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.resize(n, vector<int>(m, -1));
        return solve(0, 0, grid);
    }
};