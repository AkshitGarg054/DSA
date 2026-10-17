class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int index, int days, vector<int> &jobDifficulty) {
        if(days == 1) {
            int maxi = -1e9;
            for(int j = index; j < n; j++) maxi = max(maxi, jobDifficulty[j]);
            return maxi;
        }

        if(dp[index][days] != -1) return dp[index][days];

        int maxi = -1e9;
        int ans = 1e9;

        for(int j = index; j <= n - days; j++) { // Leave at least (days - 1) jobs for the remaining days
            maxi = max(maxi, jobDifficulty[j]);
            int remaining = solve(j + 1, days - 1, jobDifficulty);
            ans = min(ans, maxi + remaining);
        }

        return dp[index][days] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if(n < d) return -1;

        dp.assign(n, vector<int>(d + 1, -1));
        return solve(0, d, jobDifficulty);
    }
};