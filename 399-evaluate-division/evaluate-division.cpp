class Solution {
public:
    void dfs(string src, string dest, unordered_set<string> &vis, unordered_map<string, vector<pair<string, double>>> &list, double product, double &ans) {
        if(src == dest) {
            ans = product;
            return;
        }

        if(vis.count(src)) return; // if already visited
        vis.insert(src);

        for(auto [v, val] : list[src]) {
            dfs(v, dest, vis, list, product * val, ans);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> list;

        for(int i = 0; i < n; i++) {
            string u = equations[i][0], v = equations[i][1];
            double val = values[i];

            list[u].push_back({v, val});
            list[v].push_back({u, 1 / val});
        }

        vector<double> result;

        for(int i = 0; i < queries.size(); i++) {
            string src = queries[i][0];
            string dest = queries[i][1];

            double ans = -1; // -1, if invalid 
            double product = 1.0;

            if(list.count(src)) {
                unordered_set<string> vis;
                dfs(src, dest, vis, list, product, ans);
            }

            result.push_back(ans);
        }

        return result;
    }
};