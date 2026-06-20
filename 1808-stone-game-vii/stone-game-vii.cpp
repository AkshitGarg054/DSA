class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int find(int l, int r, vector<int> &prefix) {
        int sum = prefix[r];
        if(l > 0) sum -= prefix[l - 1];
        return sum;
    }

    // we need to maximize the diff
    int solve(int i, int j, vector<int> &prefix, vector<int> &stones) {
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int take_front = find(i + 1, j, prefix) - solve(i + 1, j, prefix, stones);
        int take_back = find(i, j - 1, prefix) - solve(i, j - 1, prefix, stones);

        return dp[i][j] = max(take_front, take_back);
    }

    int stoneGameVII(vector<int>& stones) {
        n = stones.size();
        
        vector<int> prefix(n);
        prefix[0] = stones[0];
        for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + stones[i];

        dp.assign(n, vector<int>(n, -1));
        int diff = solve(0, n - 1, prefix, stones);
        return diff;
    }
};