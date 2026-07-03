class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0; // contains minimum values of the entire matrix
        int col = m - 1; // contains maximum values

        while(row < n && col >= 0) {
            int val = matrix[row][col];

            if(val == target) return true;
            else if(val > target) col--;
            else row++;
        }

        return false;
    }
};