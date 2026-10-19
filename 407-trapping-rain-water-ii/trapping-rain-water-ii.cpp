class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // {height, row, col}
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][m - 1], i, m - 1});
            vis[i][0] = 1, vis[i][m - 1] = 1;
        }

        for(int j = 0; j < m; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[n - 1][j], n - 1, j});
            vis[0][j] = 1, vis[n - 1][j] = 1;
        }

        int water = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int h = it[0], r = it[1], c = it[2];

            for(auto &d: dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if(vis[nr][nc]) continue;

                vis[nr][nc] = 1;

                if(heightMap[nr][nc] < h) {
                    water += h - heightMap[nr][nc];
                    heightMap[nr][nc] = h;
                }

                pq.push({heightMap[nr][nc], nr, nc});
            }
        }

        return water;
    }
};