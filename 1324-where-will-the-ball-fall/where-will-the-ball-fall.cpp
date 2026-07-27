class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> ans(m);

        // check for each ball
        for(int j = 0; j < m; j++) {

            int i = 0, col = j;
            while(i < n && col >= 0 && col < m) {
                if(grid[i][col] == 1) {
                    if(col == m-1 || grid[i][col + 1] == -1) break; // wall or 'V'
                    else i++, col++;
                }
                else if(grid[i][col] == -1) {
                    if(col == 0 || grid[i][col - 1] == 1) break; // wall or 'V'
                    i++, col--;
                }
            }

            if(i == n) ans[j] = col;
            else ans[j] = -1;
        }

        return ans;
    }
};