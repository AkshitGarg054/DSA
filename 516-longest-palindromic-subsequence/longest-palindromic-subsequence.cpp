class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, string &s) {
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        int equal = 0, unequal = 0;

        if(s[i] == s[j]) equal = 2 + solve(i + 1, j - 1, s);
        else unequal = max(solve(i + 1, j, s), solve(i, j - 1, s));

        return dp[i][j] = max(equal, unequal);
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();

        dp.assign(n, vector<int>(n, -1));
        return solve(0, n - 1, s);
    }
};