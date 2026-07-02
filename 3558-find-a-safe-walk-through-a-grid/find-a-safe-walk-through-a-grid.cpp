class Solution {
public:
    // Normal BFS should not be applied here because here we have three states: (i, j, remaining_health).
    // We might reach same cell once after losing 5 health and again after losing 2 health.
    // A normal DFS with a vis matrix would incorrectly prune the better path.
    // Think of each move as having a path: Moving into a cell with 0 costs 0 health, and cell with 1 costs 1 health.
    // we need to find a path with minimum total health loss

    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        int startLoss = grid[0][0]; 

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // {health_loss, i, j}
        pq.push({startLoss, 0, 0});

        vector<vector<int>> dist(n, vector<int>(m, 1e9)); // stores the min health loss to reach cell (i, j)
        dist[0][0] = startLoss;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int loss = it[0];
            int r = it[1], c = it[2];

            if(r == n-1 && c == m-1) {
                if(loss < health) return true; // final health must be atleast 1, so no equality sign
                return false; // minimum loss path is greater than health
            }

            for(auto &d: dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                
                int new_loss;
                if(grid[nr][nc] == 1) new_loss = min(loss + 1, dist[nr][nc]);
                else new_loss = min(loss, dist[nr][nc]);

                if(new_loss < dist[nr][nc]) {
                    dist[nr][nc] = new_loss;
                    pq.push({new_loss, nr, nc});
                }
            }
        }

        return false;
    }
};