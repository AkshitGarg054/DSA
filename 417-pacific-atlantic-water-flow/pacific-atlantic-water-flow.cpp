class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs1(int r, int c, vector<vector<int>> &pacific, vector<vector<int>> &grid) {
        pacific[r][c] = 1;

        for(auto &d: dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(pacific[nr][nc] == 1) continue;
            if(grid[nr][nc] >= grid[r][c]) dfs1(nr, nc, pacific, grid);
        }
    }

    void dfs2(int r, int c, vector<vector<int>> &atlantic, vector<vector<int>> &grid) {
        atlantic[r][c] = 1;

        for(auto &d: dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(atlantic[nr][nc] == 1) continue;
            if(grid[nr][nc] >= grid[r][c]) dfs2(nr, nc, atlantic, grid);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m ,0));

        for(int i = 0; i < n; i++) dfs1(i, 0, pacific, heights);
        for(int j = 0; j < m; j++) dfs1(0, j, pacific, heights);

        for(int i = 0; i < n; i++) dfs2(i, m - 1, atlantic, heights);
        for(int j = 0; j < m; j++) dfs2(n - 1, j, atlantic, heights);

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1) ans.push_back({i, j});
            }
        }

        return ans;
    }
};