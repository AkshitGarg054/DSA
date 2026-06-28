class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size(); 
        int start_r = entrance[0];
        int start_c = entrance[1];

        queue<pair<int, int>> q;
        q.push({start_r, start_c});
        maze[start_r][start_c] = '+';

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [r, c] = q.front();
                q.pop();

                if(r != start_r || c != start_c) { // ~(r == start_r && c == start_c)
                    if(r == 0 || r == n-1 || c == 0 || c == m-1) return steps;
                }

                for(auto &d: dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if(maze[nr][nc] != '+') {
                        maze[nr][nc] = '+'; // mark visited
                        q.push({nr, nc});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};