class Solution {
public:
    int n, m;
    int dp[301][301];

    int solve(int i, int j, vector<vector<int>> &grid) {
        if(grid[i][j] == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1; // the cell itself 
        if(i > 0 && j > 0 && grid[i - 1][j] == 1 && grid[i][j - 1] == 1 && grid[i - 1][j - 1] == 1) {
            ans = 1 + min({solve(i - 1, j, grid), solve(i, j - 1, grid), solve(i - 1, j - 1, grid)});
        }

        return dp[i][j] = ans;
    }

    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int count = 0;

        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 1) count += solve(i, j, matrix); // side = number of square submatrices
            }
        }

        return count;
    }
};