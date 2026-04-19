class Solution {
public:
    int n;
    unordered_set<string> st;
    int dp[301];

    int solve(int index, string &s) {
        if(index == n) return true;
        if(dp[index] != -1) return dp[index];

        for(int i = index; i < n; i++) {
            string temp = s.substr(index, i - index + 1);
            if(st.count(temp)) {
                if(solve(i + 1, s) == true) return dp[index] = true;
            }
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(auto word : wordDict) st.insert(word);

        memset(dp, -1, sizeof(dp));
        return solve(0, s);
    }
};