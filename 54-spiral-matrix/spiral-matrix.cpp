class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;
        int top = 0, left = 0, right = m - 1, bottom = n - 1;

        while(top <= bottom && left <= right) {
            // top row
            for(int j = left; j <= right; j++) ans.push_back(matrix[top][j]);
            top++;

            // right column
            for(int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
            right--;

            // bottom row
            if(top <= bottom) {
                for(int j = right; j >= left; j--) ans.push_back(matrix[bottom][j]);
                bottom--;
            }

            // left column
            if(left <= right) {
                for(int i = bottom; i >= top; i--) ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};