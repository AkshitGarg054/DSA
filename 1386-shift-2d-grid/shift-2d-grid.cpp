class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m));

        k = k % (n*m);
        int index = n*m - k; // position from where we will start picking
        int j = 0; // position where we need to drop

        // from index to end
        for(int i = index; i < n*m; i++) {
            int row = i / m;
            int col = i % m;

            int trow = j / m;
            int tcol = j % m;
            ans[trow][tcol] = grid[row][col];
            j++;
        }

        // from start to index-1
        for(int i = 0; i < index; i++) {
            int row = i / m;
            int col = i % m;

            int trow = j / m;
            int tcol = j % m;
            ans[trow][tcol] = grid[row][col];
            j++;
        }

        return ans;
    }
};