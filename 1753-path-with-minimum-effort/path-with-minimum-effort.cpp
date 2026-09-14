class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9)); // to save the min effort to reach (i, j)
        dist[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq; 
        pq.push({0, {0, 0}}); // {effort, {r, c}}

        while(!pq.empty()) {
            auto [effort, cell] = pq.top();
            pq.pop();

            int r = cell.first, c = cell.second;
            if(r == n - 1 && c == m - 1) return effort;

            for(auto &d: dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                int w = abs(heights[nr][nc] - heights[r][c]);
                if(dist[nr][nc] > max(w, effort)) {
                    dist[nr][nc] = max(w, effort);
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }

        if(dist[n - 1][m - 1] == 1e9) return -1;
        return dist[n - 1][m - 1];
    }
};