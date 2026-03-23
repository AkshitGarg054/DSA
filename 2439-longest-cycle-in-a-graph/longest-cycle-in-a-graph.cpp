class Solution {
public:
    int ans = -1;

    void dfs(int u, vector<int> &vis, vector<int> &inRecursion, vector<int> &count, vector<int> &edges) {
        vis[u] = 1;
        inRecursion[u] = 1;

        int v = edges[u];
        if(v != -1) {
            if(!vis[v]) {
                count[v] = count[u] + 1;
                dfs(v, vis, inRecursion, count, edges);
            }
            else { // if vis, it means, there are chances of cycle --> but inRecursion should also be true
                if(inRecursion[v] == true) ans = max(ans, count[u] - count[v] + 1);
            }
        }

        inRecursion[u] = false;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0);
        vector<int> inRecursion(n, 0);
        vector<int> count(n, 1);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, vis, inRecursion, count, edges);
        }

        return ans;
    }
};