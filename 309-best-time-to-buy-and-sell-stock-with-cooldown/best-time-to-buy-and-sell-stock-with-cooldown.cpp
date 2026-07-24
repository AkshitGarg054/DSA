class Solution {
public:
    vector<vector<int>> dp;

    int solve(int index, bool buy, vector<int> &prices) {
        if(index >= prices.size()) {
            if(buy == true) return -1e9;
            else return 0;
        }

        if(dp[index][buy] != -1) return dp[index][buy];

        int maxi = INT_MIN;

        if(buy) {
            int sell = prices[index] + solve(index + 2, false, prices); // cooldown
            int not_sell = solve(index + 1, buy, prices);
            maxi = max(sell, not_sell);
        }
        else {
            int take = -prices[index] + solve(index + 1, true, prices);
            int skip = solve(index + 1, buy, prices);
            maxi = max(take, skip);
        }

        return dp[index][buy] = maxi;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.assign(n, vector<int>(2, -1));
        return solve(0, false, prices); // index, buy (buy = false means we can buy)
    }
};