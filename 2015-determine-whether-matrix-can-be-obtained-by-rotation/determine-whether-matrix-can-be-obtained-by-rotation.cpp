class Solution {
public:
    void rotate(int n, vector<vector<int>> &grid) {
        // take transpose
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(grid[i][j], grid[j][i]);
            }
        }

        // reverse rows
        for(int i = 0; i < n; i++) {
            reverse(grid[i].begin(), grid[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        if(mat == target) return true;

        int checks = 3;
        while(checks--) {
            rotate(n, mat);
            if(mat == target) return true;
        }

        return false;
    }
};