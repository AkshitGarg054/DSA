class Solution {
public:
    //In a two-player game with optimal play:
    // A position is a winning position for you if there is at least one move you can make that forces your opponent into a losing position.
    // A position is a losing position for you if every move you make hands your opponent a winning position.
    // The DP approach will TLE. Why??? ...even the constraints are very less then why TLE?
    // Because we can't memoize the DP solution, as we are using a used vector and it is a vector, so it can't be memoized.
    // So, we need to optimize it in a way so that vector gets removed and we can then be able to memoize it.
    // Therefore, comes the bitmasking.

    vector<int> dp; // mask itself is unique, so only 1D dp is enough

    bool solve(int sum, int mask, int n, int desired) {
        if(dp[mask] != -1) return dp[mask];

        for(int i = 1; i <= n; i++) {
            if(mask & (1 << i)) continue; // already used
            if(sum + i >= desired || solve(sum + i, mask | (1 << i), n, desired) == false) return dp[mask] = true;
        }

        return dp[mask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal) return true;
        int total = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if(total < desiredTotal) return false;

        dp.assign(1 << 21, -1); // a 20-bit number goes upto 2^20 
        return solve(0, 0, maxChoosableInteger, desiredTotal); // sum, mask
    }
};