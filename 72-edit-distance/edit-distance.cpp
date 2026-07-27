class Solution {
public:
    // s1 = "ac" , s2 = "abc"
    // At i = 1, j = 1, we need to insert b ---> s1 = "abc"
    // By doing this, i remains at 'c' and j incremented.

    int n, m;
    int dp[501][501];

    int solve(int i, int j, string &s1, string &s2) {
        if(i >= s1.size() && j >= s2.size()) return 0;
        if(i == s1.size()) return s2.size() - j; // insert operations.
        if(j == s2.size()) return s1.size() - i; // delete operations.

        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1e9;

        if(s1[i] == s2[j]) ans = min(ans, solve(i + 1, j + 1, s1, s2));
        else {
            int insert = 1 + solve(i, j + 1, s1, s2);
            int del = 1 + solve(i + 1, j, s1, s2);
            int replace = 1 + solve(i + 1, j + 1, s1, s2);
            ans = min({ans, insert, del, replace});
        }

        return dp[i][j] = ans;
    }

    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, word1, word2);
    }
};