class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q; // {row, col}
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        int time = 0;

        while(!q.empty()) {
            int sz = q.size();
            bool changed = false;

            while(sz--) {
                auto [r, c] = q.front();
                q.pop();

                for(auto &d: dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr >= n || nr < 0 || nc >= m || nc < 0) continue;
                    if(grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        changed = true;
                    }
                }
            }

            if(changed) time++;
        }

        // check if fresh oranges are still remaining
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return time;
    }
};