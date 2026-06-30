class Solution {
public:
    int n;
    vector<int> dp;

    bool check(string &s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }

    int solve(int i, string &s) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int mini = 1e9;
        string temp = "";

        for(int j = i; j < n; j++) {
            temp += s[j];
            if(check(temp)) {
                int palindromes = 1 + solve(j + 1, s);
                mini = min(mini, palindromes);
            }
        }

        return dp[i] = mini;
    }

    int minCut(string s) {
        n = s.size();

        dp.assign(n, -1);
        int ans = solve(0, s);
        ans = ans - 1; // coz we counted the number of palindromes
        return ans;
    }
};