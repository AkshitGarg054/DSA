class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, prices[i] - mini);
            mini = min(mini, prices[i]);
        }

        if(maxi < 0) return 0;
        return maxi;
    }
};