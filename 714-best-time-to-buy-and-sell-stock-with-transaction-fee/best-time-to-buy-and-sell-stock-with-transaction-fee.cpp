class Solution {
public:
    vector<vector<int>> dp;

    int solve(int index, int buy, vector<int> &prices, int fee) {
        if(index >= prices.size()) return 0;
        if(dp[index][buy] != INT_MIN) return dp[index][buy];

        int ans = INT_MIN;

        if(buy) {
            int take = -prices[index] + solve(index + 1, 0, prices, fee);
            int skip = solve(index + 1, 1, prices, fee);
            ans = max(take, skip);
        } else {
            int sell = prices[index] - fee + solve(index + 1, 1, prices, fee);
            int skip = solve(index + 1, 0, prices, fee);
            ans = max(sell, skip);
        }

        return dp[index][buy] = ans;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        dp.assign(n, vector<int>(2, INT_MIN));
        return solve(0, 1, prices, fee); // index, buy (buy = 1 means we can buy)
    }
};