class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[entrance[0]][entrance[1]] = 1;

        queue<pair<int, int>> q;

        int sx = entrance[0], sy = entrance[1];
        for(auto d : dirs) { // starting point is considered as the exit gate, so we need to start with its neighbors
            int nx = sx + d[0];
            int ny = sy + d[1];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == '.' && !vis[nx][ny]) {
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }

        int steps = 1;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [x, y] = q.front();
                q.pop();

                if(x == n-1 || x == 0 || y == 0 || y == m-1) return steps;

                for(auto d : dirs) { 
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == '.' && !vis[nx][ny]) {
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};