class Solution {
public:
    void dfs(int node, int &count, vector<int> &vis, vector<vector<int>> &list) {
        vis[node] = 1;
        count++;

        for(auto v : list[node]) {
            if(!vis[v]) dfs(v, count, vis, list);
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> list(n);

        for(int i = 0; i < n; i++) {
            long long xi = bombs[i][0];
            long long yi = bombs[i][1];
            long long ri = bombs[i][2];

            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                long long xj = bombs[j][0];
                long long yj = bombs[j][1];

                long long dist = (xi - xj)*(xi - xj) + (yi - yj)*(yi - yj);
                if(dist <= 1LL * ri * ri) list[i].push_back(j);
            }
        }

        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            vector<int> vis(n, 0);
            int count = 0;
            dfs(i, count, vis, list);
            ans = max(ans, count);
        }

        return ans;
    }
};