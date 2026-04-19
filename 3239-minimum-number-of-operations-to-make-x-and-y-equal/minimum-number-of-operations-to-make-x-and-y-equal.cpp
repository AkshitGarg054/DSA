class Solution {
public:
    vector<int> dp;

    int solve(int x, int y) {
        if(x < y) return y - x; // because if x is smaller then we can only increment it by 1-1
        if(x == y) return 0;

        if(dp[x] != -1) return dp[x];

        int dec = x - y;

        int by11 = INT_MAX;
        if(x % 11 == 0) by11 = 1 + solve(x / 11, y);
        else {
            int rem = x % 11; // eg, x = 54, y = 2 --> we either do x = 44 or x = 55
            int res1 = rem + 1 + solve((x - rem) / 11, y); // rem operations for decrementing x from 54 to 44 and 1 operation for division
            int res2 = 11 - rem + 1 + solve((x + 11 - rem) / 11, y); 
            by11 = min(res1, res2);
        }
        
        int by5 = INT_MAX;
        if(x % 5 == 0) by5 = 1 + solve(x / 5, y);
        else {
            int rem = x % 5;
            int res1 = rem + 1 + solve((x - rem) / 5, y);
            int res2 = 5 - rem + 1 + solve((x + 5 - rem) / 5, y);
            by5 = min(res1, res2);
        }

        // NOTE :  we are only using increment operation to make x divisible by 11 or 5, if it is not.
        return dp[x] = min({by11, by5, dec});
    }

    int minimumOperationsToMakeEqual(int x, int y) {
        dp.assign(x + 11, -1);
        return solve(x, y);
    }
};