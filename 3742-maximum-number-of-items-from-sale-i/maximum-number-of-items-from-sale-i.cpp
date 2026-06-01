class Solution {
public:
    vector<vector<int>> dp;

    int solve(int index, int budget, vector<int> &copies, vector<vector<int>> &items) {
        if(index == items.size() || budget == 0) return 0;
        if(dp[index][budget] != -1) return dp[index][budget];

        int price = items[index][1];
        int count = copies[index];

        int take = INT_MIN;
        if(budget >= price) take = count + solve(index + 1, budget - price, copies, items);
        int skip = solve(index + 1, budget, copies, items);

        return dp[index][budget] = max(take, skip);
    }

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
 
        dp.resize(n + 1, vector<int>(budget + 1, -1));
        int ans = 0;

        // try every possible budget split
        for(int j = 0; j <= budget; j++) {
            int max_items = solve(0, j, copies, items);

            int budget_left = budget - j;
            int extra_items = budget_left / min_price;
            ans = max(ans, max_items + extra_items);
        }

        return ans;
    }
};