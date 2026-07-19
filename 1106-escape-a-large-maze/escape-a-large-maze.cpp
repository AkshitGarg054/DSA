class Solution {
public:
    // As the number of blocked cells is atmost 200, so they can only enclose a small finite region near the start cell or the target cell.
    // From the start position, if you explore more than blocked.size() * (blocked.size() - 1) / 2 cells, you know you are not enclosed, and can directly return true.
    // Similar thing we need to check from target to start.

    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    set<pair<int, int>> st;
    int m;

    bool bfs(vector<int> &source, vector<int> &target) {
        queue<pair<int, int>> q;
        set<pair<int, int>> vis;

        q.push({source[0], source[1]});
        vis.insert({source[0], source[1]});
        int count = 1;

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if(r == target[0] && c == target[1]) return true;
            if(count > m * (m - 1) / 2) return true;

            for(auto &d: dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nr >= 1000000 || nc < 0 || nc >= 1000000) continue;
                if(st.count({nr, nc})) continue; // if blocked
                if(vis.count({nr, nc})) continue; // if visited

                vis.insert({nr, nc});
                q.push({nr, nc});
                count++;
            }
        }

        return false; 
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        m = blocked.size();
        for(int i = 0; i < blocked.size(); i++) st.insert({blocked[i][0], blocked[i][1]});

        return bfs(source, target) && bfs(target, source);
    }
};