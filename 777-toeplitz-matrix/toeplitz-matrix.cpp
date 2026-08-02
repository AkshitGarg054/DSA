class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(n == 1 || m == 1) return true;

        int row = n - 1;
        int col = 0;

        while(row >= 0) {
            int value = matrix[row][col];

            int r = row, c = col;
            while(r <= n - 1 && c <= m - 1) {
                if(matrix[r][c] != value) return false;
                r++;
                c++;
            }

            row--;
        }

        row = 0;
        col = 1;

        while(col <= m - 1) {
            int value = matrix[row][col];

            int r = row, c = col;
            while(c <= m - 1 && r <= n - 1) {
                if(matrix[r][c] != value) return false;
                r++;
                c++;
            }

            col++;
        }

        return true;
    }
};