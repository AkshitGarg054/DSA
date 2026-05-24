class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int ans = 0;

        // let's firstly send everyone to city A
        for(int i = 0; i < n; i++) ans += costs[i][0];

        // now, we need to move exactly N people from city A to B
        // change in cost for each person = CostB - costA
        // we will pick N people for which the change is most negative.

        vector<int> diff(n);
        for(int i = 0; i < n; i++) diff[i] = costs[i][1] - costs[i][0];
        sort(diff.begin(), diff.end());

        for(int i = 0; i < n/2; i++) ans += diff[i];
        
        return ans;
    }
};