class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, string &s) {
        if (i > j) return 0;
        if (i == j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int equal = 1e9, unequal = 1e9;

        if (s[i] == s[j]) equal = solve(i + 1, j - 1, s);
        else unequal = min(1 + solve(i, j - 1, s), 1 + solve(i + 1, j, s));

        return dp[i][j] = min(equal, unequal);
    }

    int minInsertions(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1, s); 
    }
};