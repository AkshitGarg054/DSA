class Solution {
public:
    const int FLAT = 0;
    const int TOP_AHEAD = 1;
    const int BOTTOM_AHEAD = 2; 
    const int MOD = 1e9 + 7;

    int numTilings(int n) {
        // This is counting DP, not optimizing DP. (Never use -1 for initializing a counting DP)
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        dp[0][FLAT] = 1; // there is 1 way to tile an empty board

        for(int i = 0; i < n; i++) {

            // state 0
            if(dp[i][FLAT] != -1) {

                if(i + 1 < n) { // fill two flat lines
                    dp[i + 2][FLAT] = (dp[i + 2][FLAT] + dp[i][FLAT]) % MOD;
                } 
                
                if(i < n) { // fill the ith column with two dots 
                    dp[i + 1][FLAT] = (dp[i + 1][FLAT] + dp[i][FLAT]) % MOD;
                }

                if(i + 1 < n) { // try to fill L shape
                    dp[i + 1][TOP_AHEAD] = (dp[i + 1][TOP_AHEAD] + dp[i][FLAT]) % MOD;
                    dp[i + 1][BOTTOM_AHEAD] = (dp[i + 1][BOTTOM_AHEAD] + dp[i][FLAT]) % MOD;
                }
            }

            if(dp[i][TOP_AHEAD] != -1) {

                if(i + 1 < n) { 
                    dp[i + 1][BOTTOM_AHEAD] = (dp[i + 1][BOTTOM_AHEAD] + dp[i][TOP_AHEAD]) % MOD; // put one flat line
                    dp[i + 2][FLAT] = (dp[i + 2][FLAT] + dp[i][TOP_AHEAD]) % MOD; // // fill with L, making the new state flat
                }
            }

            if(dp[i][BOTTOM_AHEAD] != -1) {

                if(i + 1 < n) { 
                    dp[i + 1][TOP_AHEAD] = (dp[i + 1][TOP_AHEAD] + dp[i][BOTTOM_AHEAD]) % MOD; // put one flat line
                    dp[i + 2][FLAT] = (dp[i + 2][FLAT] + dp[i][BOTTOM_AHEAD]) % MOD; // fill with L, making the new state flat
                }
            }
        }

        return dp[n][FLAT] % MOD;
    }
};