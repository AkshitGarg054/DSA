class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        parent[px] = py;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;

        // connecting allowed swaps
        for(auto &vec : allowedSwaps) unite(vec[0], vec[1]);

        unordered_map<int, unordered_map<int, int>> mp;

        for(int i = 0; i < n; i++) {
            int curr = source[i];
            int par = find(i); // group (component)
            mp[par][curr]++; // mp[par] is a unordered map
        }

        int dist = 0;

        for(int i = 0; i < n; i++) {
            int par = find(i);
            if(mp[par][target[i]] > 0) mp[par][target[i]]--;
            else dist++;
        }

        return dist;
    }
};