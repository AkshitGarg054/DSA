class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};

    bool solve(int r, int c, int num, vector<vector<int>> &grid) {
        if(num == n*n - 1) return true;

        for(auto &d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && (grid[nr][nc] == num + 1)) {
                return solve(nr, nc, num + 1, grid);
            }
        }

        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(grid[0][0] != 0) return false; 

        return solve(0, 0, 0, grid); // r, c, num
    }
};