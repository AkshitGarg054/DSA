class Solution {
public:
    int dp[101];

    int solve(int index, string &s) {
        if(index == s.size()) return 1; 
        if(s[index] == '0') return 0; 
        if(dp[index] != -1) return dp[index];

        int one = 0, two = 0;
        if(s[index] != '0') one = solve(index + 1, s);
        if(index + 1 < s.size() && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))) two = solve(index + 2, s);

        return dp[index] = one + two;
    }

    int numDecodings(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, s);
    }
};