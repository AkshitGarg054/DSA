class Solution {
public:
    // very important question (to identify the LCS pattern)
    // They must both reduce to their Longest Common Subsequence (LCS)
    // n = length of word1, m = length of word2, L = LCS(word1, word2)
    // answer = (n - L) + (m - L)

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i-1] == word2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }

        int L = dp[n][m];
        return (n - L) + (m - L);
    }
};