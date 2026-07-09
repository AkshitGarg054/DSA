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

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;

        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i - 1] <= maxDiff) {
                int u = i - 1;
                int v = i;
                unite(u, v);
            }
        }

        int m = queries.size();
        vector<bool> ans(m);

        for(int i = 0; i < m; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            if(u == v) {
                ans[i] = true;
                continue;
            }

            if(find(u) == find(v)) ans[i] = true; // if u and v are in same component
            else ans[i] = false;
        }

        return ans;
    }
};