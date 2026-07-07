class Solution {
public:
    // I think, in this question we need to return all the edges that are not involved in any cycle.
    // and those edges are called BRIDGES.
    // Tarjan's algo is used.
    int time = 1;
    vector<int> dt, low;
    vector<vector<int>> ans;

    void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &list) {
        vis[node] = 1;
        dt[node] = low[node] = time++;

        for(auto &v: list[node]) {
            if(!vis[v]) {
                dfs(v, node, vis, list);
                low[node] = min(low[node], low[v]); // compare the low of current node will all its neighbors
                if(low[v] > dt[node]) ans.push_back({node, v}); // check for bridge
            }
            else if(vis[v] && v != parent) low[node] = min(low[node], dt[v]); 
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> list(n);

        for(auto &edge: connections) {
            int u = edge[0], v = edge[1];
            list[u].push_back(v);
            list[v].push_back(u);
        }

        time = 0;
        dt.resize(n);
        low.resize(n);

        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, -1, vis, list);
        }

        return ans;
    }
};