class Solution {
public:
    void dfs(int node, int &count, vector<int> &vis, vector<vector<int>> &list) {
        vis[node] = 1;
        count++;

        for(auto &v : list[node]) {
            if(!vis[v]) dfs(v, count, vis, list);
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> list(n);

        // connect all the bombs that can be connected
        for(int i = 0; i < n; i++) {
            int xi = bombs[i][0];
            int yi = bombs[i][1];
            int ri = bombs[i][2];

            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                int xj = bombs[j][0];
                int yj = bombs[j][1];

                long long dist = 1LL*(xj - xi)*(xj - xi) + 1LL*(yj - yi)*(yj - yi);
                if(dist <= 1LL * ri * ri) list[i].push_back(j);
            }
        }

        int ans = INT_MIN;

        // apply DFS on every bomb
        for(int i = 0; i < n; i++) {
            vector<int> vis(n, 0);
            int count = 0;
            dfs(i, count, vis, list);
            ans = max(ans, count);
        }

        return ans;
    }
};