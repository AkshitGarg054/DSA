class Solution {
public:
    // In normal LIS problem, we only need the length, but here we also need the number of LIS.
    // so each state should return a pair: {length, count}
    vector<vector<pair<int, int>>> dp;

    pair<int, int> solve(int index, int prev, vector<int> &nums) {
        if(index == nums.size()) return {0, 1}; // length, count
        if(dp[index][prev + 1].first != -1) return dp[index][prev + 1];

        pair<int, int> take = {-1e9, 0};
        if(prev == -1 || (nums[index] > nums[prev])) {
            take = solve(index + 1, index, nums);
            take.first++; // include current element
        }

        auto skip = solve(index + 1, prev, nums);

        if(take.first > skip.first) return dp[index][prev + 1] = take;
        if(take.first < skip.first) return dp[index][prev + 1] = skip;
        return dp[index][prev + 1] = {take.first, take.second + skip.second}; // same maximum length, add count
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        dp.assign(n, vector<pair<int, int>>(n + 1, {-1, -1})); // right shift the index to handle prev = -1
        return solve(0, -1, nums).second;
    }
};