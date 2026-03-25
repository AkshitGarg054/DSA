class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long total_sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                total_sum += grid[i][j];
            }
        }

        if(total_sum % 2 != 0) return false;
        long long sum = total_sum / 2;

        vector<long long> row_sum(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                row_sum[i] += grid[i][j];
            }
        }

        long long s = 0;
        for(int i = 0; i < n; i++) {
            s += row_sum[i];
            if(s == sum) return true;
        }

        vector<long long> col_sum(m, 0);
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                col_sum[j] += grid[i][j];
            }
        }

        s = 0;
        for(int i = 0; i < m; i++) {
            s += col_sum[i];
            if(s == sum) return true;
        }

        return false;
    }
};