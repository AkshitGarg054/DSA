class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s1[i] == s2[j]) dp[i + 1][j + 1] = dp[i][j] + s1[i];
                else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]); 
            }
        }

        int sum1 = 0, sum2 = 0;
        for(auto ch : s1) sum1 += ch;
        for(auto ch : s2) sum2 += ch;

        return sum1 + sum2 - 2*dp[n][m];
    }
};