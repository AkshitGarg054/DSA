class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(); // columns after 90 degree rotation
        int n = boxGrid[0].size(); // rows

        for(int j = 0; j < m; j++) {
            int base = n - 1;
            for(int i = n - 1; i >= 0; i--) {
                if(boxGrid[j][i] == '*') base = i - 1;
                else if(boxGrid[j][i] == '#') {
                    if(i != base) {
                        boxGrid[j][base] = boxGrid[j][i];
                        boxGrid[j][i] = '.';
                    }
                    base = base - 1;
                }
            }
        }

        vector<vector<char>> ans(n, vector<char>(m));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[j][m - i - 1] = boxGrid[i][j];
            }
        }

        return ans;
    }
};