class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int i, int j, string &s, string &p) {
        if(i >= s.size() && j >= p.size()) return true;
        if(j >= p.size()) return false;
        if(i >= s.size()) {
            if(j + 1 < p.size() && p[j + 1] == '*') return solve(i, j + 2, s, p);
            return false;
        }
        if(p[j] >= 'a' && p[j] <= 'z' && s[i] != p[j] && (j + 1 == p.size() || p[j + 1] != '*')) return false;
        if(dp[i][j] != -1) return dp[i][j];

        if((j + 1 == p.size() || p[j + 1] != '*') && p[j] >= 'a' && p[j] <= 'z' && s[i] == p[j]) {
            if(solve(i + 1, j + 1, s, p)) return dp[i][j] = true;
        }

        if((j + 1 == p.size() || p[j + 1] != '*') && p[j] == '.') {
            if(solve(i + 1, j + 1, s, p)) return dp[i][j] = true;
        }

        // when p[j + 1] == '*'
        bool take = false, skip = false;
        if(j + 1 < p.size() && p[j + 1] == '*') {
            skip = solve(i, j + 2, s, p);
            if(p[j] == '.' || s[i] == p[j]) take = solve(i + 1, j, s, p);
        }

        return dp[i][j] = take || skip;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, s, p);
    }
};