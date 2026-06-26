class Solution {
public:
    // as, to find the shortest path from a source node to a target node, we generally use Dijkstra algo.
    // but here we have one more constraint that the number of stops to be atmost k.
    // so to handle this, we just need to add one more state into the priority queue and only consider the paths where stops <= k.
    // But there's a catch: A priority queue won't work here, coz a pq always pops the path with the cheapest cost first, regardless of stops.
    // because of the condition: if(dist[v] > d + w), we only allow a path to proceed if it gives a cheaper cost.
    // So, a normal queue needs to be used here. A queue processes level-by-level (by number of stops).

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> list(n);

        for(auto &edge: flights) {
            int u = edge[0], v = edge[1];
            int w = edge[2];
            list[u].push_back({v, w});
        }

        queue<vector<int>> q; // {dist, node, stops}
        q.push({0, src, 0});

        vector<int> dist(n, INT_MAX);
        dist[src] =  0;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int d = it[0];
            int node = it[1];
            int stops = it[2];

            if(stops > k) continue; // do not consider more than k stops

            for(auto &[v, w]: list[node]) {
                if(dist[v] > d + w) {
                    dist[v] = d + w;
                    q.push({dist[v], v, stops + 1});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};