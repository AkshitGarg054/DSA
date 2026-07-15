class Solution {
public:
    vector<vector<int>> list;
    vector<int> count;
    vector<int> ans;
    int n; // concept of this -> n = n

    // bottom up dfs (postorder)
    void dfs1(int node, int parent) {
        count[node] = 1; // every node's subtree contains atleast itself

        for(auto &child: list[node]) {
            if(child != parent) {
                dfs1(child, node);

                count[node] += count[child];
                ans[node] += ans[child] + count[child]; // the dist sum for the curr node increases by the child's distance sum + one step for every node in the child's subtree.
            }
        }
    }

    // top down dfs (preorder)
    void dfs2(int node, int parent) {

        for(auto &child: list[node]) {
            if(child != parent) {
                // old answer - (nodes getting closer) + (node getting further)
                ans[child] = ans[node] - count[child] + (n - count[child]); // Re-rooting formula
                dfs2(child, node);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this -> n = n;
        list.resize(n);
        count.resize(n, 0);
        ans.resize(n, 0);

        for(auto &edge: edges) {
            int u = edge[0], v = edge[1];
            list[u].push_back(v);
            list[v].push_back(u);
        }

        dfs1(0, -1); // populate 'count' and calculate the correct 'ans' for node 0
        dfs2(0, -1); // use node 0's answer to calculate everyone's else.
        return ans;
    }
};