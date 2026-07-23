class Solution {
public:
    int dp[46];

    int solve(int curr, int n) {
        if(curr == n) return 1;
        if(curr > n) return 0;
        if(dp[curr] != -1) return dp[curr];

        int one = solve(curr + 1, n);
        int two = solve(curr + 2, n);

        return dp[curr] = one + two;
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, n);
    }
};