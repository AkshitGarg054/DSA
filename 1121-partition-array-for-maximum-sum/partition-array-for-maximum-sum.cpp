class Solution {
public:
    int n;
    int dp[501];

    int solve(int index, vector<int> &arr, int k) {
        if(index == n) return 0;
        if(dp[index] != -1) return dp[index];

        int maxi = INT_MIN;
        int maxsum = INT_MIN;

        for(int i = index; i < min(n, index + k); i++) {
            maxi = max(maxi, arr[i]);
            int sum = maxi * (i - index + 1) + solve(i + 1, arr, k);
            maxsum = max(sum, maxsum);
        }

        return dp[index] = maxsum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, arr, k);
    }
};