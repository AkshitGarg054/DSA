class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1 || n == 0) return 0;

        queue<pair<int, int>> q; // {node, mask} 
        set<pair<int, int>> vis;

        for(int i = 0; i < n; i++) {
            int mask = (1 << i);
            q.push({i, mask});
            vis.insert({i, mask});
        }

        int final_mask = (1 << n) - 1;
        int path = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto curr = q.front();
                q.pop();

                int node = curr.first;
                int mask = curr.second;
                if(mask == final_mask) return path;

                for(auto neighbor : graph[node]) {
                    int new_mask = mask | (1 << neighbor);
                    if(!vis.count({neighbor, new_mask})) {
                        vis.insert({neighbor, new_mask});
                        q.push({neighbor, new_mask});
                    }
                }
            }

            path++;
        }

        return path;
    }
};