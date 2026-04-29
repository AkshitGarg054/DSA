class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;
    long long total = 0;
    vector<vector<long long>> dp;

    int solve(int index, long long sum, vector<int> &nums, int k) {
        if(sum >= k) return 0; // we only care about sum < k
        if(index == n) return 1; // valid subset (sum < k)
        if(dp[index][sum] != -1) return dp[index][sum];

        int take = solve(index + 1, sum + nums[index], nums, k);
        int skip = solve(index + 1, sum, nums, k);

        return dp[index][sum] = (take + skip) % MOD;
    }

    int countPartitions(vector<int>& nums, int k) {
        n = nums.size();    
        for(auto x : nums) total += x;
        if(total < 2LL * k) return 0; // not possible

        long long total_subsets = 1;
        for(int i = 0; i < n; i++) total_subsets = (total_subsets * 2) % MOD; // 2^n

        dp.resize(n, vector<long long>(k + 1, -1)); // we only need sum till k
        int bad_subsets = solve(0, 0, nums, k); // index, sum

        return (total_subsets - (2LL * bad_subsets) + MOD) % MOD;
    }
};