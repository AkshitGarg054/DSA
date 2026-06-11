class Solution {
public:
    const int MOD = 1e9 + 7;
    int max_depth = -1;

    void dfs(int node, int parent, int depth, vector<vector<int>> &list) {
        max_depth = max(depth, max_depth);

        for(auto &v: list[node]) {
            if(v == parent) continue;
            dfs(v, node, depth + 1, list);
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1; // number of nodes 
        vector<vector<int>> list(n + 1);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            list[u].push_back(v);
            list[v].push_back(u);
        }

        dfs(1, -1, 0, list); // node, parent, depth

        // ans = (1 << (max_depth - 1));
        int ans = 1;
        for(int i = 0; i < max_depth - 1; i++) ans = (ans * 2) % MOD;
        return ans;
    }
};