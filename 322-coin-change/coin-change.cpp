class Solution {
public:
    vector<vector<int>> dp;

    int solve(int index, vector<int> &coins, int target) {
        if(target == 0) return 0;
        if(target < 0) return 1e9;
        if(index == coins.size()) return 1e9;
        if(dp[index][target] != -1) return dp[index][target];

        int take = 1e9;
        if(target >= coins[index]) take = 1 + solve(index, coins, target - coins[index]);
        int skip = 0 + solve(index + 1, coins, target); 

        return dp[index][target] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        dp.assign(coins.size(), vector<int>(amount+1, -1));
        int ans = solve(0, coins, amount);

        if(ans == 1e9) return -1;
        return ans;
    }
};