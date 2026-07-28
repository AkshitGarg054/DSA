class Solution {
public:
    // This uses the concept of taking the min and second_min, instead of all elements
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m));
        int min1 = -1; // column index of first min value in (row + 1).
        int min2 = -1; // column index of second min value in (row + 1).

        for(int j = 0; j < m; j++) {
            dp[n - 1][j] = grid[n - 1][j]; // last row as same as original

            // find mini and sec_mini of last row
            if(min1 == -1 || dp[n - 1][j] < dp[n - 1][min1]) {
                min2 = min1;
                min1 = j;
            }
            else if(min2 == -1 || dp[n - 1][j] < dp[n - 1][min2]) min2 = j;
        }

        // go from bottom to up and keep calculating the results
        for(int row = n - 2; row >= 0; row--) {
            int curr_min1 = -1; // min value of curr row
            int curr_min2 = -1; // second min value of curr row

            for(int col = 0; col < m; col++) {
                if(col == min1) dp[row][col] = grid[row][col] + dp[row + 1][min2];
                else dp[row][col] = grid[row][col] + dp[row + 1][min1];

                if(curr_min1 == -1 || dp[row][col] < dp[row][curr_min1]) {
                    curr_min2 = curr_min1;
                    curr_min1 = col;
                }
                else if(curr_min2 == -1 || dp[row][col] < dp[row][curr_min2]) curr_min2 = col;
            }

            min1 = curr_min1;
            min2 = curr_min2;
        }

        return dp[0][min1];
    }
};