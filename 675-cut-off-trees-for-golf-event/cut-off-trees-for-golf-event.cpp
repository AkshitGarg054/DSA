class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int bfs(int i, int j, int di, int dj, vector<vector<int>>& forest, vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;

        int steps = 0;
        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [r, c] = q.front();
                q.pop();

                if(r == di && c == dj) return steps;

                for(auto &d: dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if(vis[nr][nc]) continue;
                    if(forest[nr][nc] == 0) continue;
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }

            steps++;
        }

        return -1; // if destination can't be reached
    }

    int cutOffTree(vector<vector<int>>& forest) {
        n = forest.size();
        m = forest[0].size();
        if(forest[0][0] == 0) return -1;

        // map is always sorted by its key. 
        map<int, pair<int, int>> mp;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(forest[i][j] != 0 && forest[i][j] != 1) mp[forest[i][j]] = {i, j};
            }
        }

        pair<int, int> start = {0, 0};
        int steps = 0;

        for(auto &it: mp) {
            int val = it.first;
            int row = it.second.first;
            int col = it.second.second;

            vector<vector<int>> vis(n, vector<int>(m, 0));
            int dist = bfs(start.first, start.second, row, col, forest, vis);
            if(dist == -1) return -1;
            steps += dist;
            
            start = {row, col};
        }

        return steps;
    }
};