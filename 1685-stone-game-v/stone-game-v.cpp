class Solution {
public:
    int n;
    vector<int> prefix;
    vector<vector<int>> dp;

    int getSum(int l, int r) {
        return prefix[r] - (l > 0 ? prefix[l - 1] : 0); 
    }

    int solve(int l, int r) {
        if(l == r) return 0; // only one element left
        if(dp[l][r] != -1) return dp[l][r];

        int ans = INT_MIN;

        for(int k = l; k < r; k++) {
            int left = getSum(l, k);
            int right = getSum(k + 1, r);

            if(left < right) ans = max(ans, left + solve(l, k));
            else if(left > right) ans = max(ans, right + solve(k + 1, r));
            else ans = max(ans, left + max(solve(l, k), solve(k + 1, r)));
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        n = stoneValue.size();

        prefix.resize(n);
        prefix[0] = stoneValue[0];
        for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + stoneValue[i];

        dp.resize(n, vector<int>(n, -1));
        return solve(0, n - 1); // (l, r)
    }
};