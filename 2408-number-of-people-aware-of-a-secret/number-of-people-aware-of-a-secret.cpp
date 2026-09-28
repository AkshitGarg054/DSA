class Solution {
public:
    const int MOD = 1e9 + 7;
    // There a diff between number of people who are eligible to share a secret on a particular day and no. of people who know the secret.
    // On day X, no. of people who are eligible to share the secret on that day, only those can share.
    // So, if eligible people = 10, then on day X, 10 more peole will get to know the secret.
    // So, at day X, 20 number people will know the secret finally.
    // Only the people who learned the secret on [n - forget + 1, n - delay] will contribute to nth day.
    // dp[i] = number of users who learn the secret on day i.

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1);
        dp[1] = 1;

        for(int day = 2; day <= n; day++) {
            for(int k = max(1, day - forget + 1); k <= (day - delay); k++) {
                dp[day] = (dp[day] + dp[k]) % MOD;
            }
        }

        long long ans = 0; // count poeple who still remember on day n.
        for(int k = max(1, n - forget + 1); k <= n; k++) {
            ans = (ans + dp[k]) % MOD;
        }

        return (int)ans;
    }
};