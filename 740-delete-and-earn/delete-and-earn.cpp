class Solution {
public:
    vector<vector<int>> dp;

    // Treat element values as Indices.
    int solve(int index, bool prev, vector<int> &points) {
        if(index == points.size()) return 0;
        if(dp[index][prev] != -1) return dp[index][prev];

        int take = -1e9, skip = -1e9;
        if(prev == false) take = points[index] + solve(index + 1, true, points);
        skip = solve(index + 1, false, points);

        return dp[index][prev] = max(take, skip);
    }

    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> points(maxi + 1, 0); // where points[x] = x * freq(x)
        for(auto &ele: nums) points[ele] += ele;

        dp.resize(points.size(), vector<int>(2, -1));
        return solve(0, false, points); // index, prev (prev = false means prev ele is not taken)
    }
};