class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[2001];

    int solve(int index, string &s) {
        // base case not needed because the loop handles termination naturally when it reaches end of string
        if(dp[index] != -1) return dp[index];

        long long ans = 0;
        vector<int> vis(26, 0);

        for(int i = index; i < s.size(); i++) {
            if(vis[s[i] - 'a'] == 0) {
                vis[s[i] - 'a'] = 1;
                ans = (ans + 1 + solve(i + 1, s)) % MOD; // 1 is added to include the char s[index] itself as a subsequence
            }
        }

        return dp[index] = ans % MOD;
    }

    int distinctSubseqII(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, s);
    }
};