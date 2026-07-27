class Solution {
public:
    int n, m;
    int dp[1001][1001];

    int solve(int i, int j, string &s, string &t) {
        if(j == t.size()) return 1; // matched complete string
        if(i == s.size() && j != t.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int take = 0, skip = 0;

        if(s[i] == t[j]) {
            take = solve(i + 1, j + 1, s, t);
            skip = solve(i + 1, j, s, t);
        }
        else {
            skip = solve(i + 1, j, s, t);
        }

        return dp[i][j] = take + skip;
    }

    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, t);
    }
};