class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // mark source visited

        int level = 1;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [r, c] = q.front();
                q.pop();

                if(r == n - 1 && c == m - 1) return level;

                for(auto &d: dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if(grid[nr][nc] == 0) {
                        grid[nr][nc] = 1; // mark visited
                        q.push({nr, nc});
                    }
                }
            }

            level++;
        }

        return -1;
    }
};