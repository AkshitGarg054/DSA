class Solution {
public:
    // we will start from all 1's together and cover all the zeros. 
    // steps will give the minimum number of steps to reach the farthest zero from the nearest 1.
    // (sb zeros ka apna apna nearest 1 hoga. Jb sabhi 1's pe BFS lgake 0s tk pohanchenge to jo zero 1 se sbse zyada dur hai usko visit kre bina loop khtm ni hoga)

    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();
            bool updated = false;

            while(sz--) {
                auto [x, y] = q.front();
                q.pop();

                for(auto d : dirs) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0 && !vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        updated = true;
                        q.push({nx, ny});
                    }
                }
            }

            if(updated) steps++;
        }

        if(steps == 0) return -1;
        return steps;
    }
};