class Solution {
public:
    int n, m;
    int dp[1001][1001];

    int solve(int i, int j, string &s1, string &s2) {
        if(i == n || j == m) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int match = 0, not_match = 0;
        if(s1[i] == s2[j]) match = 1 + solve(i + 1, j + 1, s1, s2);
        not_match = 0 + max(solve(i, j + 1, s1, s2), solve(i + 1, j, s1, s2));

        return dp[i][j] = max(match, not_match);
    }

    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, text1, text2);
    }
};