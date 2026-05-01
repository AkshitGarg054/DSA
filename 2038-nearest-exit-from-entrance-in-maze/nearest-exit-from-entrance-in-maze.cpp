class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        int start_x = entrance[0];
        int start_y = entrance[1];

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[start_x][start_y] = 1;

        queue<pair<int, int>> q;
        q.push({start_x, start_y});

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [i, j] = q.front();
                q.pop();

                if((i == 0 || i == n-1 || j == 0 || j == m-1) && !(i == start_x && j == start_y)) return steps;

                for(auto &d : dirs) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                    if(!vis[ni][nj] && maze[ni][nj] == '.') {
                        vis[ni][nj] = 1;
                        q.push({ni, nj});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};