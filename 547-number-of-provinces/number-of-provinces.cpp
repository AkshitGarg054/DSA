class Solution {
public:
    vector<vector<int>> list;

    void dfs(int node, vector<int> &vis) {
        vis[node] = 1;

        for(auto &v: list[node]) {
            if(!vis[v]) dfs(v, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        list.resize(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int u = i;
                int v = j;

                if(isConnected[u][v]) {
                    list[u].push_back(v);
                    list[v].push_back(u);
                }
            }
        }

        vector<int> vis(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, vis);
                count++;
            }
        }

        return count;
    }
};