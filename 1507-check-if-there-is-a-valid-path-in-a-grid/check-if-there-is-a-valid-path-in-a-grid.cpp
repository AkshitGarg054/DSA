class Solution {
public:
    vector<vector<int>> vis;
    int n, m;

    vector<vector<vector<int>>> links = {
        {},
        {{0, -1}, {0, 1}},
        {{-1, 0}, {1, 0}},
        {{0, -1}, {1, 0}},
        {{0, 1}, {1, 0}},
        {{0, -1}, {-1, 0}},
        {{0, 1}, {-1, 0}}
    };

    bool dfs(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        if(i == n-1 && j == m-1) return true;

        vis[i][j] = 1;

        for(auto &d : links[grid[i][j]]) {
            int ni = i + d[0];
            int nj = j + d[1];

            if(ni < 0 || nj < 0 || ni >= n || nj >= m || vis[ni][nj]) continue;
            
            // Important : check if we can come back to (i, j) from (ni, nj)
            for(auto &rd : links[grid[ni][nj]]) {
                if(ni + rd[0] == i && nj + rd[1] == j) {
                    if(dfs(ni, nj, grid) == true) return true;
                }
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vis.resize(n, vector<int>(m, 0));
        return dfs(0, 0, grid);   
    }
};