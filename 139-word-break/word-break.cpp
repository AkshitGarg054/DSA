class Solution {
public:
    vector<int> dp;
    unordered_set<string> st;

    bool solve(int i, string &s) {
        if(i == s.size()) return true;
        if(dp[i] != -1) return dp[i];

        for(int j = i; j < s.size(); j++) {
            string sub = s.substr(i, j - i + 1);
            if(st.count(sub)) {
                if(solve(j + 1, s)) return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        for(auto &s: wordDict) st.insert(s);

        dp.assign(n + 1, -1); 
        return solve(0, s);
    }
};