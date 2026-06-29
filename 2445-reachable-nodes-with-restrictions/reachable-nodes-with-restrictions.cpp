class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> st(restricted.begin(), restricted.end());
        vector<vector<int>> list(n);

        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            list[u].push_back(v);
            list[v].push_back(u);
        }

        vector<int> vis(n, 0);;

        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        int count = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            count++;

            for(auto &v: list[node]) {
                if(!vis[v] && !st.count(v)) {
                    vis[v] = 1;
                    q.push(v);
                } 
            }
        }

        return count;
    }
};