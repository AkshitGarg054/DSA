class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int r, int c, vector<vector<int>>& grid, int &count) {
        grid[r][c] = 0;
        count++;

        for(auto &d: dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(grid[nr][nc] == 1) dfs(nr, nc, grid, count);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    int count = 0;
                    dfs(i, j, grid, count);
                    ans = max(ans, count);
                }
            }
        }

        return ans;
    }
};