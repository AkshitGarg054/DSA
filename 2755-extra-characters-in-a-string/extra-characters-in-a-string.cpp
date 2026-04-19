class Solution {
public:
    // it seems difficult, but it is very easy
    // just apply take, not take pattern here also
    // either take s[i] as extra character and recurse from (i + 1)
    // or, not take s[i] as extra chacter and check upto what len, this substr is present and recurse for remaining

    int n;
    vector<int> dp;

    int solve(int index, unordered_set<string> &st, string &s) {
        if(index == n) return 0;
        if(dp[index] != -1) return dp[index];

        int ans = 1 + solve(index + 1, st, s); // take s[index] as extra character

        for(int i = index; i < n; i++) {
            string temp = s.substr(index, i - index + 1);
            if(st.count(temp)) { // not counted as extra
                ans = min(ans, solve(i + 1, st, s));
            }   
        }

        return dp[index] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();
        unordered_set<string> st;
        for(auto &it : dictionary) st.insert(it);

        dp.resize(n, -1);
        return solve(0, st, s);
    }
};