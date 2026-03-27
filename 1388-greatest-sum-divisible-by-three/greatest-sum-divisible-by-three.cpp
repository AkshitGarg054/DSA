class Solution {
public:
    vector<vector<int>> dp;

    int solve(int index, int mod, vector<int> &nums) {
        if(index == nums.size()) {
            if(mod == 0) return 0; // valid
            return -1e9; // return large -ve number to make it invalid
        }

        if(dp[index][mod] != -1) return dp[index][mod];

        int take = nums[index] + solve(index + 1, (mod + nums[index]) % 3, nums);
        int skip = 0 + solve(index + 1, mod, nums);

        return dp[index][mod] = max(take, skip);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        dp.resize(n, vector<int>(3, -1));
        return solve(0, 0, nums);
    }
};