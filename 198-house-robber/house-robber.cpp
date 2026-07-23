class Solution {
public:
    int dp[101][2];

    int solve(int index, bool prev, vector<int> &nums) {
        if(index == nums.size()) return 0;
        if(dp[index][prev] != -1) return dp[index][prev];

        int take = 0, skip = 0;
        if(prev == false) take = nums[index] + solve(index + 1, true, nums);
        skip = solve(index + 1, false, nums);

        return dp[index][prev] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        memset(dp, -1, sizeof(dp));
        return solve(0, false, nums); // index, prev ...prev = false means prev is not taken
    }
};