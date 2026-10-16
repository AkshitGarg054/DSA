class Solution {
public:
    bool isValid(int minEdge, vector<vector<pair<int, int>>> &adj, vector<bool> &online, long long k, int n) {
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    
        dist[0] = 0;
        pq.push({0, 0}); // {cost, node} 
    
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            long long cost = it.first;
            int node = it.second;

            if(cost > dist[node]) continue;
    
            for (auto it : adj[node]) {
                int v = it.first;
                int w = it.second;
                if (w < minEdge) continue;
                if (!online[v]) continue;
    
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] <= k;
    }
    
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        int maxCost = 0;
    
        vector<vector<pair<int, int>>> adj(n);
    
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].emplace_back(v, wt);
            maxCost = max(maxCost, wt);
        }
    
        int low = 0, high = maxCost, ans = -1;
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
    
            if (isValid(mid, adj, online, k, n)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    
        return ans;
    }
};