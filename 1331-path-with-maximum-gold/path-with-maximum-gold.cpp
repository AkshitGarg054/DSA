class Solution {
public:
    int n, m;

    int dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid) {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || vis[i][j]) return 0;

        vis[i][j] = 1;

        int up = grid[i][j] + dfs(i - 1, j, vis, grid);
        int down = grid[i][j] + dfs(i + 1, j, vis, grid);
        int left = grid[i][j] + dfs(i, j - 1, vis, grid);
        int right = grid[i][j] + dfs(i, j + 1, vis, grid);

        vis[i][j] = 0; // backtrack

        return max({up, down, left, right});
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) {
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    int ans = dfs(i, j, vis, grid);
                    maxi = max(ans, maxi);
                }
            }
        }

        if(maxi == INT_MIN) return 0;
        return maxi;
    }
};