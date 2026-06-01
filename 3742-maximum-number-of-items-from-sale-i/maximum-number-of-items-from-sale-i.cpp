class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int min_price = INT_MAX;
        vector<int> copies(n, 1); // start with 1 (the copy itself)

        for(int i = 0; i < n; i++) {
            min_price = min(min_price, items[i][1]);
            for(int j = 0; j < n; j++) {
                if(i != j && (items[j][0] % items[i][0] == 0)) copies[i]++;
            }
        }

        // dp[i][j] stores the max items from a subset of the first 'i' types, spending at most 'j' budget on activations (free copies wala).
        // This is the 0/1 knapsack
        vector<vector<int>> dp(n + 1, vector<int>(budget + 1, 0));

        // base cases: 0 items gained if budget is 0 or items considered is 0
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= budget; j++) dp[0][j] = 0;

        // fill the dp matrix row by row
        for(int i = 1; i <= n; i++) {
            int price = items[i - 1][1];
            int count = copies[i - 1];

            for(int j = 1; j <= budget; j++) {
                if(j >= price) { 
                    dp[i][j] = max(dp[i - 1][j], count + dp[i - 1][j - price]); // max(skip, take item) 
                }
                else dp[i][j] = dp[i - 1][j]; // not enough budget to activate, must skip
            }
        }

        // find the remaining items with the remaining budget using the final row (dp[n])
        // This is unbounded knapsack
        int ans = 0;
        for(int j = 0; j <= budget; j++) {
            int rem = budget - j;
            int extra_items = rem / min_price; // buy duplicate copies of the cheapest item
            ans = max(ans, dp[n][j] + extra_items);
        }

        return ans;
    }
};