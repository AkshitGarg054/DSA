class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int index, int sum, int target, vector<int> &nums) {
        if(index == nums.size()) {
            if(sum == target) return true;
            return false;
        } 
        if(sum > target) return false;
        if(dp[index][sum] != -1) return dp[index][sum];

        if(solve(index + 1, sum + nums[index], target, nums)) return dp[index][sum] = true;
        if(solve(index + 1, sum, target, nums)) return dp[index][sum] = true;

        return dp[index][sum] = false;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false; // odd sum

        int target = sum / 2;

        dp.assign(n, vector<int>(sum + 1, -1));
        return solve(0, 0, target, nums); // index, sum
    }
};