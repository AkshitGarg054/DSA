class Solution {
public:
    // Both person will be at the same row at any time, so we don't need to take 2 row states. (3D Dp is enough)
    int n, m;
    vector<vector<vector<int>>> dp;

    int solve(int r1, int c1, int c2, vector<vector<int>> &grid) {
        if(r1 >= n || c1 < 0 || c1 >= m) return -1e9;
        if(r1 >= n || c2 < 0 || c2 >= m) return -1e9;
        if(r1 == n - 1 && c1 != c2) return grid[r1][c1] + grid[r1][c2]; // both will reach the last row at the same time coz both are taking same number of steps
        if(r1 == n - 1 && c1 == c2) return grid[r1][c1];
        if(dp[r1][c1][c2] != 1e9) return dp[r1][c1][c2];

        int maxi = -1e9;

        if(c1 == c2) {
            int ll = grid[r1][c1] + solve(r1 + 1, c1 - 1, c2 - 1, grid);
            int ld = grid[r1][c1] + solve(r1 + 1, c1 - 1, c2, grid);
            int lr = grid[r1][c1] + solve(r1 + 1, c1 - 1, c2 + 1, grid);
            int dl = grid[r1][c1] + solve(r1 + 1, c1, c2 - 1, grid);
            int dd = grid[r1][c1] + solve(r1 + 1, c1, c2, grid);
            int dr = grid[r1][c1] + solve(r1 + 1, c1, c2 + 1, grid);
            int rl = grid[r1][c1] + solve(r1 + 1, c1 + 1, c2 - 1, grid);
            int rd = grid[r1][c1] + solve(r1 + 1, c1 + 1, c2, grid);
            int rr = grid[r1][c1] + solve(r1 + 1, c1 + 1, c2 + 1, grid);
            maxi = max({maxi, ll, ld, lr, dl, dd, dr, rl, rd, rr});
        }
        else {
            int ll = grid[r1][c1] + grid[r1][c2] + solve(r1 + 1, c1 - 1, c2 - 1, grid);
            int ld = grid[r1][c1] + grid[r1][c2] + solve(r1 + 1, c1 - 1, c2, grid);
            int lr = grid[r1][c1] + grid[r1][c2] + solve(r1 + 1, c1 - 1, c2 + 1, grid);
            int dl = grid[r1][c1] + grid[r1][c2] + solve(r1 + 1, c1, c2 - 1, grid);
            int dd = grid[r1][c1] + grid[r1][c2] + solve(r1 + 1, c1, c2, grid);
            int dr = grid[r1][c1] + grid[r1][c2] + solve(r1 + 1, c1, c2 + 1, grid);
            int rl = grid[r1][c1] + grid[r1][c2] + solve(r1 + 1, c1 + 1, c2 - 1, grid);
            int rd = grid[r1][c1] + grid[r1][c2] + solve(r1 + 1, c1 + 1, c2, grid);
            int rr = grid[r1][c1] + grid[r1][c2] + solve(r1 + 1, c1 + 1, c2 + 1, grid);
            maxi = max({maxi, ll, ld, lr, dl, dd, dr, rl, rd, rr});
        }

        return dp[r1][c1][c2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(71, vector<vector<int>>(71, vector<int>(71, 1e9)));
        return solve(0, 0, m - 1, grid);
    }
};