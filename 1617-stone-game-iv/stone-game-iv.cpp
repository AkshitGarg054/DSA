class Solution {
public:
    vector<int> dp;

    bool solve(int n) {
        if(n == 0) return false; // no stones left to pick
        if(dp[n] != -1) return dp[n];

        for(int k = 1; k*k <= n; k++) { // ry removing every perfect square k^2 < n
            if(solve(n - k*k) == false) {
                return dp[n] = true;
            }
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        dp.resize(n + 1, -1);
        return solve(n);
    }
};