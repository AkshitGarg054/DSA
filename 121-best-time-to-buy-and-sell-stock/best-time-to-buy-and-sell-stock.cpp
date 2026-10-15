class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int mini = prices[0];
        int maxi = INT_MIN;

        for(int i = 1; i < n; i++) {
            int diff = prices[i] - mini;
            maxi = max(maxi, diff);
            mini = min(mini, prices[i]);
        }

        if(maxi < 0) return 0;
        return maxi;
    }
};