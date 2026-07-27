class Solution {
public:
    // Approach 2: DP
    // In binary search approach, we were predicting the initial health, but what if we want to calculate the exact initial health in just one pass.
    // If we start at the beginning and walk forward, we have to guess our starting health, but as we don't know what's coming in the future it is impossible to calculate the exact perfect starting health from the beginning.
    // Instead of guessing from the start, let's start at the very end with the Princess and play the game in reverse.
    // For every cell, we need to calculate the power required for that cell and keep passing it backwards.
    // How to calculate the required power for every cell???
    // Every cell will ask the down cell and right cell that what amount of health do you guys need.
    // Each down and right cell with return their required power ...and the curr cell will take the min of both ...that is, y = min(right, down)
    // The curr cell knows that it already has x power, then the required power for curr cell will be: y - x. (To complete y power, x power is given by curr cell).
    // x can be both -ve or +ve.
    // If x is very large then (y - x) will become -ve, so if (y - x) <= 0 then the required power for curr cell will be 1. (coz every cell needs atleast 1 power)

    int n, m;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>> &grid) {
        if(i >= n || j >= m) return 1e9;
        if(i == n - 1 && j == m - 1) {
            if(grid[i][j] <= 0) return abs(grid[i][j]) + 1;
            else return 1;
        }

        if(dp[i][j] != -1e9) return dp[i][j];

        int right = solve(i, j + 1, grid);
        int down = solve(i + 1, j, grid);

        int required = min(right, down) - grid[i][j];
        if(required <= 0) required = 1;

        return dp[i][j] = required;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();

        dp.assign(n, vector<int>(m, -1e9));
        return solve(0, 0, dungeon);
    }
};