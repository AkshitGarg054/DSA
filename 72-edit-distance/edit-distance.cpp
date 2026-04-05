class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int solve(int i, int j, string &word1, string &word2) {
        if(i == n) return m - j; // this much extra operations are needed
        if(j == m) return n - i;
        if(dp[i][j] != -1) return dp[i][j];

        int match = INT_MAX;
        if(word1[i] == word2[j]) match = 0 + solve(i + 1, j + 1, word1, word2);

        int insert = 1 + solve(i, j + 1, word1, word2);
        int del = 1 + solve(i + 1, j, word1, word2);
        int replace = 1 + solve(i + 1, j + 1, word1, word2);

        return dp[i][j] = min({match, insert, del, replace});
    }

    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();

        dp.resize(n, vector<int>(m, -1));
        return solve(0, 0, word1, word2);
    }
};