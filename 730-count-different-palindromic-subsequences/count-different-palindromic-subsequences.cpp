class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    long long solve(int i, int j, string &s) {
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        long long unequal = 0, equal = 0;

        if(s[i] != s[j]) unequal = solve(i + 1, j, s) + solve(i, j - 1, s) - solve(i + 1, j - 1, s);
        else {
            int low = i + 1, high = j - 1;
            while(low <= high && s[low] != s[i]) low++;
            while(low <= high && s[high] != s[j]) high--;

            if(low > high) equal = 2*solve(i + 1, j - 1, s) + 2; // no character matching s[i]
            else if(low == high) equal = 2*solve(i + 1, j - 1, s) + 1; // exactly one char matching s[i]
            else equal = 2*solve(i + 1, j - 1, s) - solve(low + 1, high - 1, s);
        }

        return dp[i][j] = ((equal + unequal) % MOD + MOD) % MOD;
    }

    int countPalindromicSubsequences(string s) {
        int n = s.size();

        dp.resize(n + 1, vector<int>(n + 1, -1));
        long long ans = solve(0, n - 1, s);
        return (int)ans;
    }
};