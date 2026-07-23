class Solution {
public:
    vector<vector<int>> dp;

    int solve(int index, int prev, vector<int> &nums) {
        if(index == nums.size()) return 0;
        if(prev != -1 && dp[index][prev] != -1e9) return dp[index][prev];

        int take = 0, skip = 0;
        if(prev ==  -1 || nums[index] > nums[prev]) take = 1 + solve(index + 1, index, nums);
        skip = solve(index + 1, prev, nums);

        if(prev == -1) return max(take, skip);
        return dp[index][prev] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        dp.assign(n, vector<int>(n, -1e9));
        return solve(0, -1, nums); // index, prev_index
    }
};