class Solution {
public:
    vector<int> dp;

    int solve(int index, vector<vector<pair<int, int>>>& list) {
        if(index == list.size()) return 0;
        if(dp[index] != -1) return dp[index];

        // skip
        int maxi = solve(index + 1, list);

        // take
        for(auto [end, gold] : list[index]) {
            maxi = max(maxi, gold + solve(end + 1, list));
        }

        return dp[index] = maxi;
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {

        vector<vector<pair<int, int>>> list(n);
        for(auto &offer : offers) {
            list[offer[0]].push_back({offer[1], offer[2]}); // all intervals starting at index i
        }

        dp.resize(n, -1);
        return solve(0, list);
    }
};