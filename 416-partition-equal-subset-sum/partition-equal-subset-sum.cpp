class Solution {
public:
    int dp[201][20001];

    bool solve(int index, vector<int> &nums, int target) {
        if(target == 0) return true;
        if(index >= nums.size()) return false;
        if(dp[index][target] != -1) return dp[index][target];

        if(target >= nums[index] && solve(index + 1, nums, target - nums[index]) == true) return dp[index][target] = true;
        if(solve(index + 1, nums, target) == true) return dp[index][target] = true;
        
        return dp[index][target] = false;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(auto x : nums) sum += x;
        if(sum % 2 != 0) return false;

        memset(dp, -1, sizeof(dp));
        return solve(0, nums, sum / 2);
    }
};