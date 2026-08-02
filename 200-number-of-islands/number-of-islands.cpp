class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int r, int c, vector<vector<char>>& grid) {
        grid[r][c] = '0';

        for(auto &d: dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(grid[nr][nc] == '1') dfs(nr, nc, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }

        return count;
    }
};