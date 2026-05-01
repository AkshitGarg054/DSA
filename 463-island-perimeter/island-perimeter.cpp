class Solution {
public:
    // For each cell, we need to check ki uske neighbors pe land hai ya water.
    // As, each land cell can contribute either 0, 1, 2, 3 or 4 in the perimeter,
    // so we can simply traverse in the grid, and jb bhi land cell aaye to we can check ki uske 4 neighbors pe kya kya haii and accordingly increment the parameter.
    // so both the submitted approaches

    int n, m;

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= n || j >= m) return 1;
        if(grid[i][j] == 0) return 1;
        if(grid[i][j] == -1) return 0; // if already visited

        grid[i][j] = -1;

        int perimeter = 0;

        perimeter += dfs(grid, i+1, j);
        perimeter += dfs(grid, i-1, j);
        perimeter += dfs(grid, i, j+1);
        perimeter += dfs(grid, i, j-1);

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }

        return 0;
    }
};