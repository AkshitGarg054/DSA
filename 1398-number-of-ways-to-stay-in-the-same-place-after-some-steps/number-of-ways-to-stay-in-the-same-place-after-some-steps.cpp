class Solution {
public:
    // At every step, we have 3 choices --> Left, Right or Stay
    // observation : whatever the arrLen is, max useful index = min(arrLen - 1, steps)
    // because we can only go at max till the number of steps we have

    const int MOD = 1e9 + 7;
    long long dp[501][501];

    int solve(int index, int steps, int max_pos) {
        if(index > max_pos || index < 0 || steps < 0) return 0;
        if(index == 0 && steps == 0) return 1;
        if(dp[index][steps] != -1) return dp[index][steps];

        long long left = solve(index - 1, steps - 1, max_pos);
        long long right = solve(index + 1, steps - 1, max_pos);
        long long stay = solve(index, steps - 1, max_pos);

        return dp[index][steps] = (left + right + stay) % MOD;
    }

    int numWays(int steps, int arrLen) {
        int max_pos = min(arrLen - 1, steps);

        memset(dp, -1, sizeof(dp));
        return solve(0, steps, max_pos);
    }
};