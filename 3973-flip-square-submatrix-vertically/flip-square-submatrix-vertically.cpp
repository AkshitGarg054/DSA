class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int l = x;
        int r = x + k - 1;

        while(l < r) {
            for(int j = y; j <= y+k-1; j++) swap(grid[l][j], grid[r][j]);
            l++, r--;
        }

        return grid;
    }
};