class Solution {
public:
    vector<vector<int>> dp;
    int offset;

    int solve(int index, int target, vector<int> &nums) {
        if(index == nums.size()) return (target == 0);

        // target + offset may become negative or exceed 2*sum
        int k = dp[0].size();
        if(target + offset < 0 || target + offset >= k) return 0;
        if(dp[index][target + offset] != -1) return dp[index][target + offset];

        int add = solve(index + 1, target - nums[index], nums);
        int sub = solve(index + 1, target + nums[index], nums);

        return dp[index][target + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto x : nums) sum += x;

        offset = sum;
        dp.resize(nums.size(), vector<int>(2*sum + 1, -1));
        return solve(0, target, nums);
    }
};