class Solution {
  public:
    // using DFS, instead of topo sort
    // If cycle founds in DFS, then finishing all courses is not possible. Example : [[1, 0], [1, 2], [0, 1]], n = 3
    // To detect cycle, we need three visited states
    // 0 -> unvisited 
    // 1 -> visiting (currently in recursion stack)
    // 2 -> visited

    // this function is made to detect cycle
    bool dfs(int u, vector<vector<int>> &list, vector<int> &vis, vector<int> &ans) { 
        vis[u] = 1; // visiting
        
        for(auto v : list[u]) {
            if(vis[v] == 1) return true; // cycle found
            if(vis[v] == 0) {
                if(dfs(v, list, vis, ans) == true) return true;
            }
        }

        vis[u] = 2; // visited
        ans.push_back(u);
        return false;
    }
  
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> list(n);
        vector<int> inDegree(n, 0);
        vector<int> ans;
        
        for(auto edge : prerequisites) {
            int u = edge[1], v = edge[0];
            list[u].push_back(v);
            inDegree[v]++;
        }
        
        vector<int> vis(n, 0);
        
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                if(dfs(i, list, vis, ans)) return {};
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};