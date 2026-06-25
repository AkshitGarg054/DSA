class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int i, int j, vector<vector<char>> &grid) {
        grid[i][j] = '0';

        for(auto &d: dirs) {
            int nr = i + d[0];
            int nc = j + d[1];

            if(nr >= n || nr < 0 || nc >= m || nc < 0) continue;
            if(grid[nr][nc] == '0') continue;
            dfs(nr, nc, grid);
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