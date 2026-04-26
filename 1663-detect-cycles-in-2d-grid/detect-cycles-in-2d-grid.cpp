class Solution {
public:
    int n, m;
    vector<vector<int>> dirs =  {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool dfs(int i, int j, int pi, int pj, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        vis[i][j] = 1;

        for(auto &d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];

            if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if(grid[ni][nj] != grid[i][j]) continue;
            if(!vis[ni][nj]) {
                if(dfs(ni, nj, i, j, grid, vis)) return true;
            }
            else if(vis[ni][nj] == true && (ni != pi && nj != pj)) return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    if(dfs(i, j, -1, -1, grid, vis)) return true;
                }
            }
        }

        return false;
    }
};