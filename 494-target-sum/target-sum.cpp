class Solution {
public:
    vector<vector<int>> dp;
    int offset;
    int sum;

    int solve(int index, int target, vector<int> &nums) {
        if(index == nums.size()) {
            if(target == 0) return 1;
            else return 0;
        }

        // can't write: target + offset >= dp[0].size() 
        if(target + offset < 0 || target + offset >= 2*sum + 1) return 0;
        if(dp[index][target + offset] != -1) return dp[index][target + offset];

        int add = solve(index + 1, target - nums[index], nums);
        int sub = solve(index + 1, target + nums[index], nums);

        return dp[index][target + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        sum = 0;
        for(auto ele : nums) sum += ele;

        offset = sum;
        dp.resize(n, vector<int>(2*sum + 1, -1));
        return solve(0, target, nums);
    }
};