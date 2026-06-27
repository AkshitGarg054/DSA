class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e8));
        for(int i = 0; i < n; i++) dist[i][i] = 0;

        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    // only update if both paths exist
                    if(dist[i][via] != 1e8 && dist[via][j] != 1e8) {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        int mini = INT_MAX;
        int ans;

        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= distanceThreshold) count++;
            }

            if(count <= mini) {
                mini = count;
                ans = i;
            }
        }

        return ans;
    }
};