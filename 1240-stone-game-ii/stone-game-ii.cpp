class Solution {
public:
    vector<vector<int>> dp;

    int solve(int index, int M, vector<int> &suffix, vector<int> &piles) {
        if(index == piles.size()) return 0;
        if(index + 2*M >= piles.size()) return suffix[index]; // we can take the entire remaining piles as each person tries to maximize its stones
        if(dp[index][M] != -1) return dp[index][M];

        int result = 0;
        for(int x = 1; x <= 2*M; x++) {
            result = max(result, suffix[index] - solve(index + x, max(x, M), suffix, piles));
        }

        return dp[index][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        if(n == 0) return 0;

        vector<int> suffix(n);
        suffix[n-1] = piles[n-1];
        for(int i = n-2; i >= 0; i--) suffix[i] = suffix[i + 1] + piles[i];

        dp.resize(n, vector<int>(n, -1));
        return solve(0, 1, suffix, piles); // index, M
    }
};