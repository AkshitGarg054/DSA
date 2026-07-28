class Solution {
public:
    int n, m;
    vector<vector<vector<vector<int>>>> dp;

    int solve(int r1, int c1, int r2, int c2, vector<vector<int>> &grid) {
        if(r1 < 0 || r1 >= n || c1 < 0 || c1 >= m) return -1e9;
        if(r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) return -1e9;
        if(grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1e9;
        if(r1 == n - 1 && c1 == m - 1) return grid[r1][c1]; // both are taking same number of steps, so both will reach the destination together
        if(dp[r1][c1][r2][c2] != 1e9) return dp[r1][c1][r2][c2];

        int ans = -1e9;

        if(r1 == r2 && c1 == c2) { // both are on the same cell
            int dd = grid[r1][c1] + solve(r1 + 1, c1, r2 + 1, c2, grid);
            int rr = grid[r1][c1] + solve(r1, c1 + 1, r2, c2 + 1, grid);
            int dr = grid[r1][c1] + solve(r1 + 1, c1, r2, c2 + 1, grid);
            int rd = grid[r1][c1] + solve(r1, c1 + 1, r2 + 1, c2, grid);
            ans = max({ans, dd, rr, dr, rd});
        }
        else {
            int dd = grid[r1][c1] + grid[r2][c2] + solve(r1 + 1, c1, r2 + 1, c2, grid);
            int rr = grid[r1][c1] + grid[r2][c2] + solve(r1, c1 + 1, r2, c2 + 1, grid);
            int dr = grid[r1][c1] + grid[r2][c2] + solve(r1 + 1, c1, r2, c2 + 1, grid);
            int rd = grid[r1][c1] + grid[r2][c2] + solve(r1, c1 + 1, r2 + 1, c2, grid);
            ans = max({ans, dd, rr, dr, rd});
        }
        
        return dp[r1][c1][r2][c2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(grid[0][0] == -1 || grid[n - 1][m - 1] == -1) return 0;

        // two person start together from (0, 0)
        dp.assign(51, vector<vector<vector<int>>>(51, vector<vector<int>>(51, vector<int>(51, 1e9))));
        int ans = solve(0, 0, 0, 0, grid);

        if(ans < 0) return 0;
        return ans;
    }
};