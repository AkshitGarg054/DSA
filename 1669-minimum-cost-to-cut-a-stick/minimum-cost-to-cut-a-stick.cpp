class Solution {
public:
    long long f(int i, int j, vector<int> &cuts, vector<vector<long long>> &dp) {
        if(i + 1 >= j) return 0; // [1, 2] --> no cut can be applied on this

        if(dp[i][j] != -1) return dp[i][j];

        long long mini = LLONG_MAX;
        for(int k = i + 1; k <= j - 1; k++) {
            long long cost = (cuts[j] - cuts[i]) + f(i, k, cuts, dp) + f(k, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<long long>> dp(cuts.size(), vector<long long>(cuts.size(), -1));

        long long ans = f(0, cuts.size() - 1, cuts, dp); // pass i = 0 and j = n - 1 
        return (int)ans;
    }
};