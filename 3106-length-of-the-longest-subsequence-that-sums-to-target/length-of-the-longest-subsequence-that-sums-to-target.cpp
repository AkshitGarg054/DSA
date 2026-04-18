class Solution {
public:
    vector<vector<int>> dp;

    int solve(int index, int sum, int target, vector<int> &nums) {
        if(sum == target) return 0;
        if(index == nums.size()) return INT_MIN;
        if(dp[index][sum] != -1) return dp[index][sum]; 

        int take = INT_MIN;

        if(sum + nums[index] <= target) {
            int res = solve(index + 1, sum + nums[index], target, nums);
            if(res != INT_MIN) take = 1 + res; 
        }

        int skip = solve(index + 1, sum, target, nums);

        return dp[index][sum] = max(take, skip);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();

        dp.assign(n, vector<int>(1001, -1));
        int ans = solve(0, 0, target, nums);
        
        if(ans == INT_MIN) return -1;
        return ans;
    }
};