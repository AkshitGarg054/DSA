class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(auto &d: dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if(dist[nr][nc] != -1) continue;

                if(grid[nr][nc] == 0) {
                    dist[nr][nc] = 1 + dist[r][c];
                    q.push({nr, nc});
                }
            }
        }

        int maxi = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                maxi = max(maxi, dist[i][j]);
            }
        }

        if(maxi == 0) return -1;
        return maxi;
    }
};