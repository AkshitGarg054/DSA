class Solution {
public:
    // as, to find the shortest path from a source node to a target node, we generally use Dijkstra algo.
    // but here we have one more constraint that the number of stops to be atmost k.
    // so to handle this, we just need to add one more state into the priority queue and only consider the paths where stops <= k.

    // But there's a catch: A priority queue won't work here, coz a pq always pops the path with the cheapest cost first, regardless of stops.
    // because of the condition: if(dist[v] > d + w), we only allow a path to proceed if it gives a cheaper cost.
    // Example: Say, we need to go from A to D with an intermediate node C. There are two paths from A to C:
    // Path 1: costs 10 and stops = 5
    // Path 2: costs 50 and stops = 1
    // given, k = 6 and there are two direct edges from C to D.
    // Now, our dist[C] from A is already set to 10 which is minimum but this path uses a lot of stops which will exceed our limit of k = 6 stops while going from C to D.
    // Due to the condition if(dist[v] > d + w), we will not be able to update the dist[C] from 10 to 50.

    // So, a normal queue needs to be used here. A queue processes level-by-level (by number of stops).
    // It evaluates all paths with 0 stops, then all paths with 1 stop, then 2 stops, and so on.

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