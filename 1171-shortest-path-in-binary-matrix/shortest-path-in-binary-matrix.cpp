class Solution {
public:
    // Similar matrix question are seen in DP also.
    // To identify DP or graph --
    // Use graphs when :
    // There are multiple directions from a point.
    // We want the shortest path.
    // Can revisit cells
    // Use DP when :
    // Overlapping subproblems
    // Directions are restricted.
    // Problem is about counting/optimizing over choices.

    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<int, int>> q;
        q.push({0, 0}); // {row, col}

        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;

        int steps = 1;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [x, y] = q.front();
                q.pop();

                if(x == n-1 && y == n-1) return steps;

                for(auto d : dirs) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0 && !vis[nx][ny]) {
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