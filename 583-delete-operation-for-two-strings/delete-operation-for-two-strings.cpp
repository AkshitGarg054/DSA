class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, string &word1, string &word2) {
        if (i == word1.size()) return word2.size() - j;
        if (j == word2.size()) return word1.size() - i;

        if (dp[i][j] != -1) return dp[i][j];

        int del = 1e9, not_delete = 1e9;

        if (word1[i] == word2[j]) {
            not_delete = solve(i + 1, j + 1, word1, word2);
        }
        else del = min(1 + solve(i + 1, j, word1, word2), 1 + solve(i, j + 1, word1, word2));

        return dp[i][j] = min(del, not_delete);
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        dp.assign(n, vector<int>(m, -1));

        return solve(0, 0, word1, word2);
    }
};