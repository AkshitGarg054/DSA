class Solution {
public:
    int find(int x, vector<int> &parent) {
        if(x == parent[x]) {
            return x;
        }

        return parent[x] = find(parent[x], parent);
    }

    void unionSet(int u, int v, vector<int> &parent) {
        int up_u = find(u, parent);
        int up_v = find(v, parent);

        if(up_u != up_v) parent[up_u] = up_v;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        // simple logic: Count the number of components and return (components - 1)
        // This will be the minimum number of operations to make the graph connected

        vector<int> parent(n);
        for(int i=0; i < n; i++) parent[i] = i;

        for(auto edge : connections) {
            unionSet(edge[0], edge[1], parent);
        }

         // Count unique parents (connected components)
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i, parent) == i) components++;
        }

        return components - 1;
    }
};