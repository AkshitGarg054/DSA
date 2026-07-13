class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // {height, row, col}
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // push all the boundary cells into the pq
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    pq.push({heightMap[i][j], i, j});
                    vis[i][j] = true;
                }
            }
        }

        int water = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int h = it[0];
            int r = it[1], c = it[2];

            for(auto &d: dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    if(heightMap[nr][nc] < h) water += (h - heightMap[nr][nc]);
                    pq.push({max(h, heightMap[nr][nc]), nr, nc});
                }
            }
        }

        return water;
    }
};