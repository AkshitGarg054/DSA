class Solution {
public:
    bool isConnected(int r1, int r2, int c1, int c2, int i, int j) {
        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;

        if(rows * cols == 1) return false; // only one cell
        if(rows > 1 && cols > 1) return true; // always connected in this case
        if(rows == 1 && (j == c1 || j == c2)) return true; // if one row, then removing element should be at corners
        if(cols == 1 && (i == r1 || i == r2)) return true;

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long total = 0;

        // store the position of every element
        unordered_map<long long, vector<pair<int, int>>> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mp[grid[i][j]].push_back({i, j});
                total += grid[i][j];
            }
        }

        vector<long long> row_sum(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                row_sum[i] += grid[i][j];
            }
        }

        vector<long long> col_sum(m, 0);
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                col_sum[j] += grid[i][j];
            }
        }

        long long sum_up = 0;
        // try making cut at every horizontal position
        for(int cut = 1; cut < n; cut++) {
            sum_up += row_sum[cut-1];
            long long sum_down = total - sum_up;
            if(sum_up == sum_down) return true;

            long long diff = abs(sum_up - sum_down);
            if(!mp.count(diff)) continue; // if element = diff, does not exist

            // if exists, check if it exists in the larger-sum part
            for(auto pos : mp[diff]) {
                int row = pos.first;
                int col = pos.second;

                if(row < cut && sum_up > sum_down && isConnected(0, cut-1, 0, m-1, row, col)) return true;
                else if(row >= cut && sum_down > sum_up && isConnected(cut, n-1, 0, m-1, row, col)) return true; 
            }
        }

        long long sum_left = 0;
        // try making cuts at every vertical position
        for(int cut = 1; cut < m; cut++) {
            sum_left += col_sum[cut-1];
            long long sum_right = total - sum_left;

            if(sum_left == sum_right) return true;

            long long diff = abs(sum_left - sum_right);
            if(!mp.count(diff)) continue;

            for(auto &pos : mp[diff]) {
                int row = pos.first;
                int col = pos.second;

                if(col < cut && sum_left > sum_right && isConnected(0, n-1, 0, cut-1, row, col)) return true;
                else if(col >= cut && sum_right > sum_left && isConnected(0, n-1, cut, m-1, row, col)) return true;
            }
        }

        return false;
    }
};