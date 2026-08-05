class Solution {
public:
    unordered_set<int> st; // contains all the suspicious nodes
    vector<vector<int>> list;

    void dfs(int node, vector<int> &vis) {
        vis[node] = 1;
        st.insert(node);

        for(auto &v: list[node]) {
            if(!vis[v]) dfs(v, vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        list.resize(n);

        for(auto &edge: invocations) {
            int u = edge[0];
            int v = edge[1];
            list[u].push_back(v);
        }

        vector<int> vis(n, 0);
        dfs(k, vis);

        vector<int> ans; // contains the proper non-suspicious node

        for(int i = 0; i < n; i++) {
            if(!st.count(i)) ans.push_back(i);
        }

        // now, if any suspicious node is directly invoked by any good node, then the whole suspicious group become good.
        for(auto &node: ans) { // good node
            for(auto &v: list[node]) { // suspicious node
                if(st.count(v)) {
                    vector<int> all; // then there is no suspicious node, coz the whole group becomes good
                    for(int i = 0; i < n; i++) all.push_back(i);
                    return all;
                }
            }
        }

        return ans;
    }
};