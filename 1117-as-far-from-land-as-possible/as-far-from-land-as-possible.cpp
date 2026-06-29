class Solution {
public:
    // for every 0 cell, calculate the distance to its nearest 1
    // and then take the maximum of all distances.
    // instead of running BFS from all 0s one by one
    // run BFS from all 1s together, the last zero reached will be our answer

    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) q.push({i, j});
            }
        }

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();
            bool added = false;

            while(sz--) {
                auto [r, c] = q.front();
                q.pop();

                for(auto &d: dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if(grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                        added = true;
                    }
                }
            }

            if(added) steps++;
        }
        
        if(steps == 0) return -1;
        return steps;
    }
};