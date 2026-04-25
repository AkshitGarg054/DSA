class Solution {
public:
    // dp[i] = true → current player can win with i stones
    // dp[i] = false → current player will lose with i stones
    // From i, we can remove any perfect square: 1, 4, 9, 16....
    // So, if there exists a move such that dp[i - square] == false, then dp[i] = true.
    // Because we move to a losing state for the opponent, so we win.
    // dp[0] = false.
    // So, the simple approach is :
    // Try removing every perfect square k^2 <= n
    // If any move leads to a losing state for opponent → we win.

    vector<int> dp;

    // this is top down approach
    bool solve(int n) {
        if(n == 0) return false; // no stones left to pick
        if(dp[n] != -1) return dp[n];

        for(int k = 1; k*k <= n; k++) { // try removing every perfect square k^2 < n
            if(solve(n - k*k) == false) {
                return dp[n] = true;
            }
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        // dp.resize(n + 1, -1);
        // return solve(n);

        dp.resize(n + 1, 0); // all false initially

        for(int i = 1; i <= n; i++) {
            for(int k = 1; k*k <= i; k++) {
                if(dp[i - k*k] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};