class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int row, int col, vector<vector<int>> &tri) {
        if(row == n) return 0;
        if(dp[row][col] != -1e9) return dp[row][col];

        int down = tri[row][col] + solve(row + 1, col, tri);
        int right = tri[row][col] + solve(row + 1, col + 1, tri); // we can always go right (coz next row always increase one ele)

        return dp[row][col] = min(down, right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        dp.resize(n, vector<int>(n, -1e9));
        return solve(0, 0, triangle); // row, col
    }
};