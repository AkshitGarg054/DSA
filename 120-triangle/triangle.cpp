class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>> &grid) {
        if(i >= n || j >= i + 1) return 1e9; // ith row has (i + 1) columns
        if(i == n - 1 && j < n) return grid[i][j];
        if(dp[i][j] != -1e9) return dp[i][j];

        int down = grid[i][j] + solve(i + 1, j, grid);
        int next = grid[i][j] + solve(i + 1, j + 1, grid);

        return dp[i][j] = min(down, next); 
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();

        dp.assign(n, vector<int>(n, -1e9));
        return solve(0, 0, triangle);
    }
};