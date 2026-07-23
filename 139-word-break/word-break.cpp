class Solution {
public:
    vector<vector<int>> dp;
    unordered_set<string> st;

    bool solve(int i, int j, string &s) {
        if(i >= s.size() && j >= s.size()) return true;
        if(j >= s.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];

        string sub = s.substr(i, j - i + 1);

        if(st.count(sub)) {
            if(solve(j + 1, j + 1, s)) return dp[i][j] = true; // start new
            if(solve(i, j + 1, s)) return dp[i][j] = true; // extend
        }
        else {
            if(solve(i, j + 1, s)) return dp[i][j] = true; // extend
        }
        
        return dp[i][j] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        for(auto &s: wordDict) st.insert(s);

        dp.assign(n + 1, vector<int>(n + 1, -1));
        return solve(0, 0, s);
    }
};