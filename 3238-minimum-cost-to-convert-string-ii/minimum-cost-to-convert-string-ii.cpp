class Solution {
public:
    int n, m, sz;
    unordered_map<string, int> id;
    vector<long long> dp;

    long long solve(int index, string &source, string &target, vector<string> &original, vector<string> &changed, vector<vector<long long>> &dist) {
        if(index == source.size()) return 0;
        if(dp[index] != -1) return dp[index];

        long long mini = LLONG_MAX;

        // we can try skipping this index
        if(source[index] == target[index]) mini = min(mini, solve(index + 1, source, target, original, changed, dist));

        // try every replacement
        for(int k = 0; k < m; k++) {
            int len = original[k].size();
            if(index + len > n) continue; // can't possible to replace with this 
            
            bool matched = true;
            // 'original' must match the 'source' and 'changed' must match the 'target'.
            // but we should not check for 'changed' == 'target' because it can also happen that for ab -> ef: ab -> cd and then cd -> ef.
            // we don't need to search for dist["ab"]["cd"] and dist["cd"]["ef"] separately, we can directly search for dist["ab"]["ef"].
            for(int i = 0; i < len; i++) {
                if(original[k][i] != source[index + i]) {
                    matched = false;
                    break;
                }
            }

            if(matched) { // only then we are try replacing 
                string targetSub = target.substr(index, len);

                if(id.count(targetSub)) {
                    int u = id[original[k]];
                    int v = id[targetSub]; 
                    if(dist[u][v] != INT_MAX) {
                        long long next = solve(index + len, source, target, original, changed, dist);
                        if(next != LLONG_MAX) mini = min(mini, (long long)dist[u][v] + next);
                    }
                }
            }
        }

        return dp[index] = mini;
    }

    void floydWarshall(vector<string> &original, vector<string> &changed, vector<int> &cost, vector<vector<long long>> &dist) {

        for(int i = 0; i < m; i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // apply floyd warshall
        for(int via = 0; via < sz; via++) {
            for(int i = 0; i < sz; i++) {
                for(int j = 0; j < sz; j++) {
                    dist[i][j] = min(dist[i][j], (long long)dist[i][via] + dist[via][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        n = source.size();
        m = cost.size();
        
        for(int i = 0; i < m; i++) {
            if(!id.count(original[i])) id[original[i]] = id.size();
            if(!id.count(changed[i])) id[changed[i]] = id.size();
        }

        sz = id.size();
        vector<vector<long long>> dist(sz, vector<long long>(sz, INT_MAX));
        for(int i = 0; i < sz; i++) dist[i][i] = 0;
        floydWarshall(original, changed, cost, dist);

        // As, In the first version of this question, we only had character to replace with. 
        // But here, we have strings, and we don't know how much part of the string we can replace when we are at current index i.
        // This is very similar to extend or start new substring pattern in DP.
        // so, we will solve this using DP (1D DP).
        dp.assign(n, -1);
        long long ans = solve(0, source, target, original, changed, dist);

        if(ans == LLONG_MAX) return -1;
        return ans;
    }
};