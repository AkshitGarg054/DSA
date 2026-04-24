class Solution {
public:
    int dp[1001][1001];
    int n;

    int solve(int index, int limit, vector<int> &prices) {
        if(index == prices.size()) return 0;

        int new_limit = min(n - 1, index + (index + 1)); // new limit becomes till next (index + 1) 
        if(dp[index][limit] != -1) return dp[index][limit];

        int buy = prices[index] + solve(index + 1, new_limit, prices); 

        // buy for free only if the fruit is inside limit
        int free = INT_MAX;
        if(index <= limit) free = 0 + solve(index + 1, limit, prices);

        return dp[index][limit] = min(buy, free);
    }

    int minimumCoins(vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));

        int cost = prices[0];
        cost += solve(1, 1, prices); // start from 0st index; we can buy the next 1 (i + 1) fruits for free
        return cost;
    }
};