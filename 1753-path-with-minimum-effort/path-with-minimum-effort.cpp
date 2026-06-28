class Solution {
public:
    // we used queue in this soln, but queue can't be used because here edge weights are different
    // so to find the mini effort path, we need to revisit the visited edges, which we can't do in normal BFS.
    // We can modify it by using the effort array instead of vis array. (just like dijkstra)
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));

        queue<pair<pair<int, int>, int>> q; // {{row, col}, maxi_diff}
        q.push({{0, 0}, INT_MIN});
        effort[0][0] = 0;

        int mini = INT_MAX;

        while(!q.empty()) {
            auto [it, maxi] = q.front();
            q.pop();
            auto [r, c] = it;

            for(auto &d: dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                int diff = abs(heights[nr][nc] - heights[r][c]);
                int new_effort = max(maxi, diff); // stores the maxi diff for a path till this (nr, nc) cell

                if(effort[nr][nc] > new_effort) {
                    effort[nr][nc] = new_effort;
                    q.push({{nr, nc}, new_effort});
                }
            }
        }

        return effort[n-1][m-1];
    }
};