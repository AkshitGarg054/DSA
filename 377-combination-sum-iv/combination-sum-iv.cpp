class Solution {
public:
    vector<int> dp;

    // In this question, we also need to go back, so we don't need an index parameter at all.   
    int solve(int index, int sum, int target, vector<int> &nums) {
        if(sum == target) return 1;
        if(sum > target) return 0;
        if(dp[sum] != -1) return dp[sum];

        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(sum + nums[i] <= target) ans += solve(i + 1, sum + nums[i], target, nums);
            // doing only ans = solve(...) erases the result of previous loop iterations. But we need to accumulate them.
        }

        return dp[sum] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();

        dp.assign(target + 1, -1);
        return solve(0, 0, target, nums);
    }
};