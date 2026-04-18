class Solution {
public:
    vector<vector<int>> dp;

    int solve(int index, int sum, int target, vector<int> &vec) {
        if(sum == target) return 1;
        if(index == vec.size()) return 0;
        if(dp[index][sum] != -1) return dp[index][sum];

        int take = INT_MIN;
        if(sum + vec[index] <= target) take = vec[index] * solve(index, sum + vec[index], target, vec);
        int skip = solve(index + 1, sum, target, vec);

        return dp[index][sum] = max(take, skip);
    }

    int integerBreak(int n) {
        vector<int> vec;
        for(int i = 1; i < n; i++) vec.push_back(i);

        dp.assign(vec.size(), vector<int>(60, -1));
        return solve(0, 0, n, vec);
    }
};