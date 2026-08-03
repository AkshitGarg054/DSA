class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        int sx = entrance[0];
        int sy = entrance[1];

        queue<pair<int, int>> q;
        q.push({sx, sy});

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[sx][sy] = 1;

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [r, c] = q.front();
                q.pop();

                if((r == 0 || r == n-1 || c == 0 || c == m-1) && (r != sx || c != sy)) return steps;

                for(auto &d: dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if(maze[nr][nc] == '+') continue;
                    if(vis[nr][nc]) continue;

                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }

            steps++;
        }

        return -1;
    }
};