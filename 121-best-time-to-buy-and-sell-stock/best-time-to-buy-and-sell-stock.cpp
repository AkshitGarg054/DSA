class Solution {
public:
    // no need for DP here.
    // this is not like, buy -> sell -> buy -> sell........
    // it is just buy -> sell -> stop.
    // for every element on left, we want a greater element on the right
    // and take the one, which is giving the max profit.
    // basically, we want minimum from left and maximum from right.

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = INT_MAX;
        int profit = 0;

        for(int i = 0; i < n; i++) {
            mini = min(mini, prices[i]);
            profit = max(profit, prices[i] - mini);
        }

        return profit;
    }
};