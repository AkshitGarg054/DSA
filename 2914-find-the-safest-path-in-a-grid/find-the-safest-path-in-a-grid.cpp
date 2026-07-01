class Solution {
public:
    // This approach gives TLE because here to calculate the dist matrix we are traversing all the thieves for each 0 cell.
    // To calculate the dist matrix optimally, we can do so by applying multi source BFS from all thieves.
    // Now, still this soln gives TLE, coz we are traversing all the paths using DFS.
    // To reduce these paths traversal, we can use Binary Search + BFS. (Method 1)
    // For this, check whether there exists a path where dist[cell] >= x for every cell on the path.
    // Or, we can use the Priority queue approach: state = (minimum safeness till here, row, col)

    int n, m;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> dist;
    vector<vector<int>> vis;
    int maxi = INT_MIN;

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(grid[0][0] == 1) return 0;

        // find the minimum distance of every 0 from all thiefs
        // we will apply multi-source BFS from all thieves for this.
        vis.assign(n, vector<int>(m, 0));
        dist.assign(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [r, c] = q.front();
                q.pop();

                for(auto &d: dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if(vis[nr][nc]) continue;

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }

        // Use dijkstra
        priority_queue<vector<int>> pq; // {currMin, row, col} ...use max-heap coz we want the maximum minimum
        vector<vector<int>> best(n, vector<int>(m, -1));

        pq.push({dist[0][0], 0, 0});
        best[0][0] = dist[0][0];

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int mini = it[0];
            int r = it[1], c = it[2];

            if(r == n-1 && c == m-1) return mini;

            for(auto &d: dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            
                int new_mini = min(mini, dist[nr][nc]);
                if(new_mini > best[nr][nc]) { // coz we are using max heap and want the maximum
                    best[nr][nc] = new_mini;
                    pq.push({best[nr][nc], nr, nc});
                }
            }
        } 

        return -1;
    }
};