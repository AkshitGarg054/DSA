class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(int index, int count_a, int count_b, vector<vector<int>> &costs) {
        if(count_a > n/2 || count_b > n/2) return 1e9;
        if(index == n) {
            if(count_a == (n / 2) && count_a == count_b) return 0;
            else return 1e9;
        }

        if(dp[index][count_a][count_b] != -1) return dp[index][count_a][count_b];

        int take_a = costs[index][0] + solve(index + 1, count_a + 1, count_b, costs);
        int take_b = costs[index][1] + solve(index + 1, count_a, count_b + 1, costs);

        return dp[index][count_a][count_b] = min(take_a, take_b);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        n = costs.size();

        dp.resize(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(0, 0, 0, costs);
    }
};