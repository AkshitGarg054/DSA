class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int ans = INT_MIN;

        for(int i = 1; i < n; i++) {
            ans = max(ans, prices[i] - mini);
            mini = min(mini, prices[i]);
        }

        if(ans < 0) return 0;
        return ans;
    }
};