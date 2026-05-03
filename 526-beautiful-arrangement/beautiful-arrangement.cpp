class Solution {
public:
    // in this question, we needed to track that which numbers are already used.
    // for this, we can use bitmask, instead of vis array.

    vector<int> dp;

    int solve(int mask, int n) {
        int pos = __builtin_popcount(mask) + 1; // due to 1 based index
        if(pos > n) return 1; // all visited --> one permuation added
        if(dp[mask] != -1) return dp[mask];

        int count = 0;

        // try all numbers from 1 to n
        for(int num = 1; num <= n; num++) {
            // if not vis
            if(!(mask & (1 << (num - 1)))) {
                if(num % pos == 0 || pos % num == 0) {
                    count += solve(mask | (1 << (num - 1)), n);
                }
            }
        }

        return dp[mask] = count;
    }

    int countArrangement(int n) {
        dp.resize(1 << n, -1);
        return solve(0, n); // mask
    }
};