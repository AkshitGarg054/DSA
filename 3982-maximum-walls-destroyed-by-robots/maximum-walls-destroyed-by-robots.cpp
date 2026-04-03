class Solution {
public:
    vector<vector<int>> dp;

    int count_walls(vector<int> &walls, int l, int r) {
        int lb = lower_bound(walls.begin(), walls.end(), l) - walls.begin();
        int ub = upper_bound(walls.begin(), walls.end(), r) - walls.begin();
        return ub - lb;
    }

    int solve(int i, int prev_dir, vector<int> &walls, vector<pair<int, int>> &roboDist, vector<pair<int, int>> &range) {
        if(i == roboDist.size()) return 0;
        if(dp[i][prev_dir] != -1) return dp[i][prev_dir];

        int left_start = range[i].first;
        if(i > 0 && prev_dir == 1) { // if prev robot fired towards right
            left_start = max(left_start, range[i-1].second + 1);
        }

        int left_walls = count_walls(walls, left_start, roboDist[i].first) + solve(i + 1, 0, walls, roboDist, range);
        int right_walls = count_walls(walls, roboDist[i].first, range[i].second) + solve(i + 1, 1, walls, roboDist, range);

        return dp[i][prev_dir] = max(left_walls, right_walls);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<pair<int, int>> roboDist(n);
        for(int i = 0; i < n; i++) roboDist[i] = {robots[i], distance[i]};

        sort(roboDist.begin(), roboDist.end());
        sort(walls.begin(), walls.end());

        // finding true left and right range for each robot
        vector<pair<int, int>> range(n);

        for(int i = 0; i < n; i++) {
            int pos = roboDist[i].first;
            int dist = roboDist[i].second;

            int left = pos - dist;
            int right = pos + dist;

            if(i > 0) left = max(left, roboDist[i - 1].first + 1);
            if(i < n - 1) right = min(right, roboDist[i + 1].first - 1);

            range[i] = {left, right};
        }

        dp.resize(n, vector<int>(2, -1));
        return solve(0, 0, walls, roboDist, range); // index, chosen dir of prev robot (0 for left and 1 for right)
    }
};