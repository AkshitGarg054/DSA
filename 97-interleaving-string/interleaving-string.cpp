class Solution {
public:
    // There are two possibilites for each char of s3: either s3[i] belongs to s1 or it belongs to s2.
    int n, m;
    int dp[101][101];

    bool solve(int i, int j, string &s1, string &s2, string &s3) {
        if(i == n && j == m) return true;
        if(dp[i][j] != -1) return dp[i][j];
        
        int k = i + j; // curr index of s3

        if(s1[i] == s3[k]) {
            if(solve(i + 1,  j, s1, s2, s3)) return dp[i][j] = true;
        }

        if(s2[j] == s3[k]) {
            if(solve(i, j + 1, s1, s2, s3)) return dp[i][j] = true;
        }

        return dp[i][j] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();
        if(n + m != s3.size()) return false;

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s1, s2, s3);
    }
};