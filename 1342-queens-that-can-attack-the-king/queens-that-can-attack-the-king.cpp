class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int n = queens.size();
        vector<vector<int>> ans;

        set<pair<int, int>> st;
        for(auto q : queens) st.insert({q[0], q[1]});
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

        for(auto [dx, dy] : dirs) {
            int x = king[0], y = king[1];
            
            while(true) {
                x += dx;
                y += dy;


                if(x < 0 || x >= 8 || y < 0 || y >= 8) break; 
                if(st.count({x, y})) {
                    ans.push_back({x, y});
                    break; // break from this direction.
                }
            }
        }

        return ans;
    }
};