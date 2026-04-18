class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& grid) {
        if(j == m - 1) return 0;
        if(i < 0 || i >= n || j >= m) return INT_MIN;
        if(dp[i][j] != -1) return dp[i][j];

        int up = 0, down = 0, straight = 0;
        
        if(i - 1 >= 0 && grid[i-1][j+1] > grid[i][j]) up = 1 + solve(i - 1, j + 1, grid);
        if(j + 1 < m && grid[i][j+1] > grid[i][j]) straight = 1 + solve(i, j + 1, grid);
        if(i + 1 < n && grid[i+1][j+1] > grid[i][j]) down = 1 + solve(i + 1, j + 1, grid);

        return dp[i][j] = max({up, down, straight});
    }

    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<int>(m, -1));

        int maxi = 0;
        for(int i = 0; i < n; i++) {
            int moves = solve(i, 0, grid);
            maxi = max(moves, maxi);
        }

        return maxi;
    }
};