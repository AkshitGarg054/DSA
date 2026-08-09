class Solution {
public:
    int dp[101][3];

    int solve(int index, int prev, vector<int> &nums) {
        if(index == nums.size()) return 0;
        if(prev != -1 && dp[index][prev] != -1) return dp[index][prev];

        int take = -1e9;
        int skip = -1e9;

        if(prev == 1) skip = solve(index + 1, 0, nums);
        else {
            take = nums[index] + solve(index + 1, 1, nums);
            skip = solve(index + 1, 0, nums);
        }

        if(prev == -1) return max(take, skip);
        return dp[index][prev] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        memset(dp, -1, sizeof(dp));
        int ans = solve(0, -1, nums); // 1 is prev is taken
        return ans;
    }
};