class Solution {
public:
    vector<vector<pair<int, int>>> list;
    unordered_map<int, int> mp; // last seen depth for every node
    vector<int> prefix; // to get the total weight of the selected sub path.
    int max_len = 0;
    int min_nodes = 1e9;

    void dfs(int node, int parent, int curr, int start, vector<int> &nums) {
        int val = nums[node];

        // save the old start for backtracking later
        int old_start = -1; 
        if(mp.count(val)) old_start = mp[val];

        int new_start = start;
        if(mp.count(val)) new_start = max(start, mp[val] + 1); // now we have a subpath from (new_start, curr)
        int len = prefix[curr] - prefix[new_start]; // path sum
        int num_nodes = curr - new_start + 1;

        if(len > max_len) {
            max_len = len;
            min_nodes = num_nodes;
        }
        else if(len == max_len) min_nodes = min(min_nodes, num_nodes);

        mp[val] = curr; // store the new latest depth of node

        // visit neighbors
        for(auto &it: list[node]) {
            int v = it.first;
            int w = it.second;

            if(v != parent) {
                prefix[curr + 1] = prefix[curr] + w; // curr is the curr_depth, not the curr node.
                dfs(v, node, curr + 1, new_start, nums);
            }
        }

        // backtrack: undo the last occcurences 
        if(old_start != -1) mp[val] = old_start;
        else mp.erase(val); // if the value appeared now for the first time
    }

    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        list.resize(n);
        prefix.resize(n, 0);

        for(auto &edge: edges) {
            int u = edge[0], v = edge[1];
            int wt = edge[2];
            list[u].push_back({v, wt});
            list[v].push_back({u, wt});
        }

        // we want: node, parent, curr_depth, start_depth
        dfs(0, -1, 0, 0, nums); // parent is used to prevent revisiting the nodes

        return {max_len, min_nodes};
    }
};