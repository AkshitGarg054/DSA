class Solution {
public:
    vector<vector<long long>> dp;

    long long solve(int ri, int fi, vector<int> &robot, vector<int> &factories) {
        if(ri >= robot.size()) return 0;
        if(fi >= factories.size()) return LLONG_MAX / 2; // if factories exhausted but robots are still remaining
        if(dp[ri][fi] != -1) return dp[ri][fi];

        long long take = abs(robot[ri] - factories[fi]) + solve(ri + 1, fi + 1, robot, factories);
        long long skip = 0 + solve(ri, fi + 1, robot, factories);

        return dp[ri][fi] = min(take, skip);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factories;
        for(int i = 0; i < factory.size(); i++) {
            int limit = factory[i][1];
            int pos = factory[i][0];
            for(int j = 0; j < limit; j++) factories.push_back(pos);
        }

        int f = factories.size();

        dp.assign(n, vector<long long>(f, -1));
        return solve(0, 0, robot, factories); // robot_index, factory_index
    }
};