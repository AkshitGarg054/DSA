class Solution {
public:
    vector<int> dp;

    // for every index, we have three options, either take one-day pass or 7-day or 30-day.
    int solve(int index, vector<int> &days, vector<int> &costs) {
        if(index == days.size()) return 0;
        if(dp[index] != -1) return dp[index];

        int one = costs[0] + solve(index + 1, days, costs);

        int next = lower_bound(days.begin(), days.end(), days[index] + 7) - days.begin(); // next index
        int seven = costs[1] + solve(next, days, costs);

        next = lower_bound(days.begin(), days.end(), days[index] + 30) - days.begin(); // next index
        int thirty = costs[2] + solve(next, days, costs);

        return dp[index] = min({one, seven, thirty});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        dp.assign(n, -1);
        return solve(0, days, costs);
    }
};