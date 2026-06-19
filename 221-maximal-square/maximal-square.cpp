class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<char>> &matrix) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int left = solve(i, j - 1, matrix);
        int up = solve(i - 1, j, matrix);
        int diag = solve(i - 1, j - 1, matrix);

        return dp[i][j] = 1 + min({left, up, diag});
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        dp.assign(n, vector<int>(m, -1));
        int side = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') side = max(side, solve(i, j, matrix));
                else dp[i][j] = 0;
            }
        }

        return side * side;
    }
};