class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // create prefix matrix 
        vector<vector<pair<int, int>>> prefix(n, vector<pair<int, int>>(m, {0, 0})); // {x, y}
        if(grid[0][0] == 'X') prefix[0][0] = {1, 0};
        else if(grid[0][0] == 'Y') prefix[0][0] = {0, 1};

        for(int i = 1; i < n; i++) {
            prefix[i][0].first = prefix[i-1][0].first + (grid[i][0] == 'X' ? 1 : 0);
            prefix[i][0].second = prefix[i-1][0].second + (grid[i][0] == 'Y' ? 1 : 0);
        }

        for(int j = 1; j < m; j++) {
            prefix[0][j].first = prefix[0][j-1].first + (grid[0][j] == 'X' ? 1 : 0);
            prefix[0][j].second = prefix[0][j-1].second + (grid[0][j] == 'Y' ? 1 : 0);
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                prefix[i][j].first = (grid[i][j] == 'X' ? 1 : 0) + prefix[i-1][j].first + prefix[i][j-1].first - prefix[i-1][j-1].first;
                prefix[i][j].second = (grid[i][j] == 'Y' ? 1 : 0) + prefix[i-1][j].second + prefix[i][j-1].second - prefix[i-1][j-1].second;
            }
        }

        int count = 0;
        
        // just iterate on the prefix matrix and count the number of prefix cells where x == y 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(prefix[i][j].first == prefix[i][j].second && prefix[i][j].first > 0) count++;
            }
        }
        
        return count;
    }
};