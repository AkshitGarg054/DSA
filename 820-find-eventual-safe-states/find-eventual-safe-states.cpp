class Solution {
public:
    // each outgoing edge of every node should lead to a terminal edge.
    // there can be only options for any outgoing edge: either it can reach terminal or it will loop in a cycle or both.
    // any node who is a part of a cycle or any node that leads to a cycle cannot be a safe node.
    // So, how to find these nodes??
    // We need to know the technique of how to detect a cycle in directed graph using DFS (tracking nodes in the current recursion stack ...used this technique in Course Schedule Problem).

    bool checkCycle(int node, vector<int> &vis, vector<int> &inRecursion, vector<vector<int>>& graph) {
        vis[node] = true;
        inRecursion[node] = true;

        for(auto &v: graph[node]) {
            if(!vis[v]) {
                if(checkCycle(v, vis, inRecursion, graph)) return true; // cycle is there
            }
            else if(vis[v] == true && inRecursion[v] == true) return true; // cycle is there
        }

        inRecursion[node] = false; // this will not be able to undo, if we found a cycle
        return false; 
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> inRecursion(n, 0);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) checkCycle(i, vis, inRecursion, graph);
        }

        // all the nodes for which inRecursion is true will be the non-safe nodes.
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            if(inRecursion[i] == true) st.insert(i);
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(!st.count(i)) ans.push_back(i);
        }

        return ans;
    }
};