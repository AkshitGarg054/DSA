class Solution {
public:
    int dp[302][302];

    int solve(int i, int j, vector<int> &nums) {
        if(i + 1 >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        long long maxi = INT_MIN;

        for(int k = i + 1; k <= j - 1; k++) {
            long long cost = 1LL * nums[i] * nums[k] * nums[j];
            long long coins = cost + solve(i, k, nums) + solve(k, j, nums);
            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        memset(dp, -1, sizeof(dp));
        int ans = solve(0, nums.size() - 1, nums);
        return ans;
    }
};