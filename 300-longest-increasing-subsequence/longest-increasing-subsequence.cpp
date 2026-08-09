class Solution {
public:
    int dp[2501][2501];

    int solve(int index, int prev, vector<int> &nums) {
        if(index == nums.size()) return 0;
        if(prev != -1 && dp[index][prev] != -1) return dp[index][prev];

        int take = -1e9;
        int skip = -1e9;

        if(prev == -1 || nums[index] > nums[prev]) {
            take = 1 + solve(index + 1, index, nums);
            skip = solve(index + 1, prev, nums);
        }
        else skip = solve(index + 1, prev, nums);

        if(prev == -1) return max(take, skip);
        return dp[index][prev] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        memset(dp, -1, sizeof(dp));
        int ans = solve(0, -1, nums);
        return ans;
    }
};