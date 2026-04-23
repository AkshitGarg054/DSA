class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[31][1001];

    int solve(int index, int sum, int k, int n, int target) {
        if(index == n + 1) {
            if(sum == target) return 1;
            else return 0;
        }

        if(dp[index][sum] != -1) return dp[index][sum];

        long long count = 0;
        for(int i = 1; i <= k; i++) {
            if(sum + i <= target) count = (count + solve(index + 1, sum + i, k, n, target)) % MOD;
        }

        return dp[index][sum] = count;
    }

    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(1, 0, k, n, target);
    }
};