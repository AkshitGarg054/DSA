class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k, -1)));
        int ans = solve(0, 1, 0, prices, dp, k);
        return ans == INT_MIN ? 0 : ans;
    }

    // buy and sell, if canBuy==1 then pick and notPick else pick and notPick
    int solve(int idx, int canBuy, int cnt, vector<int>& prices, vector<vector<vector<int>>>& dp, int k) {
        if(cnt >= k) return 0;
        if(idx >= prices.size()) return 0;

        if(dp[idx][canBuy][cnt] != -1) return dp[idx][canBuy][cnt];

        int choice1 = INT_MIN;
        int choice2 = INT_MIN;

        if(canBuy == 1)
            choice1 = max(-prices[idx] + solve(idx+1, 0, cnt, prices, dp, k), solve(idx+1, 1, cnt, prices, dp, k));
        else
            choice2 = max(prices[idx] + solve(idx+1, 1, cnt+1, prices, dp, k), solve(idx+1, 0, cnt, prices, dp, k));

        return dp[idx][canBuy][cnt] = max(choice1, choice2);
    }
};