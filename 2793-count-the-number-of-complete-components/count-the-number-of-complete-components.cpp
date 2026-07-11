class Solution {
public:
    // If a connected component has V vertices, how many edges must it have to be considered complete?
    // The first vertex must connect to (V-1) other vertices.
    // The second vertex must connect to (V-1) other vertices.
    // In total, the sum of the "degrees" of all vertices in that component must be exactly V*(V - 1).
    // Therefore, count the number of edges and nodes in each connected component and then check the condition for complete connected comp.

    void dfs(int node, int &nodes, int &edges, vector<vector<int>> &list, vector<int> &vis) {
        vis[node] = 1;
        nodes++;
        edges += list[node].size();

        for(auto &v: list[node]) {
            if(!vis[v]) dfs(v, nodes, edges, list, vis);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> list(n);
        
        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            list[u].push_back(v);
            list[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int node_count = 0, edge_count = 0;
                dfs(i, node_count, edge_count, list, vis); // node, node_count, edge_count
                if(edge_count == node_count * (node_count - 1)) count++;
            }
        }

        return count;
    }
};