class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int val = it[0], row = it[1], col = it[2];
            if(row == n - 1 && col == n - 1) return val;

            for(auto &d: dirs) {
                int nr = row + d[0];
                int nc = col + d[1];

                if(nr >= n || nr < 0 || nc >= n || nc < 0) continue;
                if(vis[nr][nc]) continue;

                vis[nr][nc] = 1;
                pq.push({max(val, grid[nr][nc]), nr, nc});
            }
        }

        return -1;
    }
};