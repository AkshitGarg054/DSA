class Solution {
public:
    unordered_set<string> m;
    unordered_map<string, int> dp;

    int solve(string& s) {
        if(dp.count(s)) return dp[s];
        int maxi = 1;

        for (int i = 0; i < s.length(); i++) {
            string temp = s;
            temp.erase(i, 1);
            if (m.count(temp)) maxi = max(maxi, 1 + solve(temp));
        }

        return dp[s] = maxi;
    }

    int longestStrChain(vector<string>& words) {
        for(auto& w : words) m.insert(w);
        int ans = 1;

        for (auto& w : words) ans = max(ans, solve(w));
        return ans;
    }
};