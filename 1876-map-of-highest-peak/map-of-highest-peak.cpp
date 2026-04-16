class Solution {
public:
    // start level order BFS from all the water cells together
    // "steps" will give the final answer when the loop finishes.

    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(auto d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && isWater[nx][ny] == 0 && !vis[nx][ny]) {
                    ans[nx][ny] = ans[x][y] + 1;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return ans;
    }
};