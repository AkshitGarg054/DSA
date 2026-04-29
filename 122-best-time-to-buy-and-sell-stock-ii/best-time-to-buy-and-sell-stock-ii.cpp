class Solution {
public:
    int n;
    int dp[30001][2];

    int solve(int index, int can_buy, vector<int> &prices) {
        if(index == n) return 0;
        if(dp[index][can_buy] != -1) return dp[index][can_buy];
        
        int maxi = INT_MIN;

        if(can_buy) { // it can choose to buy or skip
            int buy = -prices[index] + solve(index + 1, 0, prices);
            int skip = 0 + solve(index + 1, 1, prices);
            maxi = max({maxi, buy, skip});
        }
        else { // can sell or skip
            int sell = prices[index] + solve(index + 1, 1, prices);
            int skip = 0 + solve(index + 1, 0, prices);
            maxi = max({maxi, sell, skip});
        }

        return dp[index][can_buy] = maxi;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, prices); // index, toggle (toggle = 1 means we can buy)
    }
};