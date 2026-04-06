class Solution {
public:
    int solve(int index, vector<int> &nums, vector<int> &dp) {
        if(index >= nums.size()) return 0;
        if(index == nums.size() - 1) return nums[index];
        if(dp[index] != -1) return dp[index];

        int pick = nums[index] + solve(index + 2, nums, dp);
        int skip = 0 + solve(index + 1, nums, dp);

        return dp[index] = max(pick, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1, temp2;

        // As here, first and last elements are adjacent, so they can never occur together
        for(int i = 0; i < n; i++) {
            if(i != 0) temp1.push_back(nums[i]); 
            if(i != n-1) temp2.push_back(nums[i]); 
        }

        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);

        int ans1 = solve(0, temp1, dp1);
        int ans2 = solve(0, temp2, dp2);

        return max(ans1, ans2);
    }
};