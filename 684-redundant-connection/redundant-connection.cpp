class Solution {
public:
    // we need to detect the cycle and then cycle wala edge return krna haii.
    // instead of building the whole graph at once, we can build the graph edge by edge, exactly in the order they appear in the input.
    // When we process an edge [u, v], we connect (Union) the set containing u with the set containing v.
    // If we process an edge [u, v] and find that u and v are already in the same set, it means there is already a path between them. Adding this new edge directly connects them again, forming a cycle!

    vector<int> parent;

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return false; // already connected
        parent[px] = py;
        return true; // connected now
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);
        for(int i = 1; i <= n; i++) parent[i] = i;

        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            if(unite(u, v) == false) return edge;
        }

        return {}; 
    }
};