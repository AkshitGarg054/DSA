class Solution {
public:
    int count = 0;

    long long dfs(int node, int parent, vector<vector<int>> &list, vector<int> &values, int k) {
        long long sum = values[node];

        for(auto &child : list[node]) {
            if(child == parent) continue;
            sum += dfs(child, node, list, values, k);
        }

        if(sum % k == 0) {
            count++;
            return 0; // cut here, so pass zero upward
        }

        return sum; // pass remaining sum to parent
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> list(n);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            list[u].push_back(v);
            list[v].push_back(u);
        }

        dfs(0, -1, list, values, k);
        return count;
    }
};