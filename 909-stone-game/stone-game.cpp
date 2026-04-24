class Solution {
public:
    int dp[501][501];

    int solve(int l, int r, vector<int> &piles) {
        if(l == r) return piles[r];
        if(dp[l][r] != -1) return dp[l][r];

        int pick_left = piles[l] - solve(l + 1, r, piles);
        int pick_right = piles[r] - solve(l, r - 1, piles);

        return dp[l][r] = max(pick_left, pick_right);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));

        int diff = solve(0, n - 1, piles);
        return diff > 0;
    }
};