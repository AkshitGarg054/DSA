class Solution {
public:
    // each outgoing edge of every node should lead to a terminal edge.
    // there can be only options for any outgoing edge: either it can reach terminal or it will loop in a cycle or both.
    // any node who is a part of a cycle or any node that leads to a cycle cannot be a safe node.
    // So, how to find these nodes??
    // We need to know the technique of how to detect a cycle in directed graph using DFS (tracking nodes in the current recursion stack ...used this technique in Course Schedule Problem).

    // we can also solve this using topological sort. (but we need to reverse the edges)

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> list(n);
        vector<int> indegree(n, 0);
        
        for(int i = 0; i < n; i++) {
            for(auto &v: graph[i]) {
                list[v].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto &v: list[node]) {
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};