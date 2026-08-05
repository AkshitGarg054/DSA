class Solution {
public:
    int n;
    vector<vector<int>> list;

    bool dfs(int node, vector<int> &vis) {
        vis[node] = 1;

        for(auto &v: list[node]) {
            if(vis[v] == 1) return true;
            else if(vis[v] == 0) {
                if(dfs(v, vis)) return true;
            }
        }

        vis[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses; 

        list.resize(n);
        for(auto &edge: prerequisites) {
            int u = edge[1];
            int v = edge[0];
            list[u].push_back(v);
        }

        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(dfs(i, vis)) return false; // dfs returns true if cycle is present
            }
        }

        return true;
    }
};