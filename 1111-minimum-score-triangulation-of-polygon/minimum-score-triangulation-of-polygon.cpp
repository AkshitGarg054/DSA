class Solution {
public:
    int dp[51][51];

    int solve(int i, int j, vector<int> &v) {
        if(i + 1 == j) return 0; // i--j is a single edge
        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for(int k = i + 1; k < j; k++) {
            ans = min(ans, v[i]*v[k]*v[j] + solve(i, k, v) + solve(k, j, v));
        }

        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        memset(dp, -1, sizeof(dp));
        return solve(0, n - 1, values);
    }
};