class Solution {
public:
    // we need the maximum time taken to reach any employee, that is, the max root-to-leaf path sum
    void dfs(int node, int curr, int &maxi, vector<vector<int>> &list, vector<int> &vis, vector<int> &informTime) {
        vis[node] = 1;

        for(auto &v: list[node]) {
            if(!vis[v]) {
                maxi = max(maxi, curr);
                dfs(v, curr + informTime[node], maxi, list, vis, informTime);
            }
        }

        maxi = max(maxi, curr);
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> list(n);

        for(int i = 0; i < n; i++) {
            int u = manager[i];
            int v = i;
            if(u != -1) list[u].push_back(v);
        }

        int maxi = INT_MIN;
        vector<int> vis(n, 0);
        dfs(headID, 0, maxi, list, vis, informTime);
        return maxi;
    }
};