class Solution {
public:
    int calc(vector<vector<int>> &grid, int i, int j, int k) {
        // convert 2D submatrix into a vector
        vector<int> vec;

        for(int r = i; r < i+k; r++) {
            for(int c = j; c < j+k; c++) {
                vec.push_back(grid[r][c]);
            }
        }

        sort(vec.begin(), vec.end());
        if(vec.size() == 1) return 0;

        int min_diff = INT_MAX;

        for(int it = 1; it < vec.size(); it++) {
            int diff = abs(vec[it] - vec[it-1]);
            if(diff == 0) continue;
            min_diff = min(diff, min_diff);
        }

        if(min_diff == INT_MAX) return 0;
        return min_diff;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n-k+1, vector<int>(m-k+1));

        for(int i = 0; i < n-k+1; i++) {
            for(int j = 0; j < m-k+1; j++) {
                ans[i][j] = calc(grid, i, j, k);
            }
        }

        return ans;
    }
};