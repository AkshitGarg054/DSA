class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1) return -1;
        if(grid[n - 1][m - 1] == 1) return -1;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[0][0] = 1;

        queue<pair<int, int>> q;
        q.push({0, 0});

        int count = 1;

        while(!q.empty()) {
            int sz = q.size();
            bool found = false;

            while(sz--) {
                auto [r, c] = q.front();
                q.pop();

                if(r == n - 1 && c == m - 1) return count;

                for(auto &d: dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if(grid[nr][nc] == 1) continue;
                    if(vis[nr][nc]) continue;

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                    found = true;
                }
            }

            if(found) count++;
        }

        return -1;
    }
};