class Solution {
public:
    int dp[101];

    int solve(int index, string &s) {
        if(index == s.size()) return 1;
        if(s[index] == '0') return 0;
        if(dp[index] != -1) return dp[index];

        int single = solve(index + 1, s);

        int pair = 0;
        if(index + 1 < s.size() && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))) pair = solve(index + 2, s);

        return dp[index] = pair + single;
    }

    int numDecodings(string s) {
        int n = s.size();
        if(s[0] == '0') return 0;

        memset(dp, -1, sizeof(dp));
        return solve(0, s);
    }
};