class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(int r1, int c1, int r2, vector<vector<int>> &grid) {
        int c2 = r1 +  c1 - r2; // (r1 + c1 == r2 +  c2)

        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1e9;
        if(r1 == n-1 && c1 == n-1) return grid[r1][c1];
        if(dp[r1][c1][r2] != -1) return dp[r1][c1][r2];

        int ans = 0;
        if(r1 == r2 && c1 == c2) ans += grid[r1][c1];
        else ans += grid[r1][c1] + grid[r2][c2];

        int dd = ans + solve(r1+1, c1, r2+1, grid); // down, down
        int rr = ans + solve(r1, c1+1, r2, grid);   // right, right
        int dr = ans + solve(r1+1, c1, r2, grid);   // down, right
        int rd = ans + solve(r1, c1+1, r2+1, grid);  // right, down
        
        return dp[r1][c1][r2] = max({dd, rr, dr, rd}); 
    }
 
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        if(grid[n-1][n-1] == -1 || grid[0][0] == -1) return 0;

        dp.resize(51, vector<vector<int>>(51, vector<int>(51, -1)));

        int ans = solve(0, 0, 0, grid); // r1, c1, r2 (r1 + c1 == r2 +  c2)
        return max(0, ans);
    }
};