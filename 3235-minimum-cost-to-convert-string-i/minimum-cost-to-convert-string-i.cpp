class Solution {
public:
    int n, m;

    void floydWarshall(vector<char> &original, vector<char> &changed, vector<int> &cost, vector<vector<long long>> &dist) {

        for(int i = 0; i < m; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // apply floyd warshall
        for(int via = 0; via < 26; via++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        n = source.size();
        if(n != target.size()) return false;
        m = cost.size();

        vector<vector<long long>> dist(26, vector<long long>(26, INT_MAX));
        floydWarshall(original, changed, cost, dist);

        long long ans = 0;

        for(int i = 0; i < n; i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if(u == v) continue;
            else if(dist[u][v] != INT_MAX) ans += dist[u][v];
            else return -1;
        }

        return ans;
    }
};