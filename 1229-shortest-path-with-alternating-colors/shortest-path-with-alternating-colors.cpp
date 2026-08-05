class Solution {
public:
    // This seems like Dijkstra, but we need to use BFS only, because
    // here the edge weights are 1, so BFS will be used.

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n), blue(n);

        for(auto &edge: redEdges) {
            int u = edge[0], v = edge[1];
            red[u].push_back(v);
        }

        for(auto &edge: blueEdges) {
            int u = edge[0], v = edge[1];
            blue[u].push_back(v);
        }

        queue<tuple<int, int, int>> q;
        q.push({0, 0, -1}); // {dist, node, prev_color} ...0 for blue and 1 for red 

        // as we can start either from red or from blue edge, so we need to keep two diff arrays to consider both cases
        vector<int> redDist(n, INT_MAX), blueDist(n, INT_MAX);
        redDist[0] = 0;
        blueDist[0] = 0;

        while(!q.empty()) {
            auto [d, node, prev] = q.front();
            q.pop();

            if(prev == 0 || prev == -1) {
                for(auto &v: red[node]) {
                    int newDist = 1 + d;
                    if(redDist[v] > newDist) {
                        redDist[v] = newDist;
                        q.push({redDist[v], v, 1});
                    }
                }
            }
            
            if(prev == 1 || prev == -1) {
                for(auto &v: blue[node]) {
                    int newDist = 1 + d;
                    if(blueDist[v] > newDist) {
                        blueDist[v] = newDist;
                        q.push({blueDist[v], v, 0});
                    }
                }
            }
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int best = min(redDist[i], blueDist[i]);
            ans[i] = (best == INT_MAX ? -1 : best);
        }

        return ans;
    }
};