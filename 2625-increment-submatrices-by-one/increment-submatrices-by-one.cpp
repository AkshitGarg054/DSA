class Solution {
public:
    // Difference array technique (DAT) on 2D matrix
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n, 0));

        for(auto q : queries) {
            int r1 = q[0], c1 = q[1];
            int r2 = q[2], c2 = q[3];

            for(int i = r1; i <= r2; i++) {
                diff[i][c1] += 1;
                if(c2 + 1 < n) diff[i][c2 + 1] -= 1;
            }
        }

        // take prefix sum
        for(int r = 0; r < n; r++) {
            for(int c = 1; c < n; c++) {
                diff[r][c] += diff[r][c - 1];
            }
        }

        return diff;
    }
};