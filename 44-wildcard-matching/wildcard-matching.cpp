class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, string &s, string &p) {
        if(j == p.size()) return i == s.size();
        if(i == s.size()){
            for(int k = j; k < p.size(); k++){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j] == '*') {
            bool same = solve(i + 1, j, s, p); // s = "aab" , p = "*b" 
            bool extend = solve(i + 1, j + 1, s, p);
            bool match_empty = solve(i, j + 1, s, p); // s = "adceb" , p = "*a*b"
            if(same || extend || match_empty) return dp[i][j] =  true;
        }
        else if(p[j] == '?') {
            if(solve(i + 1, j + 1, s, p)) return dp[i][j] =  true;
        }
        else if(s[i] == p[j]) {
            if(solve(i + 1, j + 1, s, p)) return dp[i][j] =  true;
        }
        else return false;

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        if (n == 0) {
            int j = 0;
            while (j < p.size() && p[j] == '*') j++;
            return j == p.size();
        }

        dp.resize(n, vector<int>(m, -1));
        return solve(0, 0, s, p);
    }
}; 
