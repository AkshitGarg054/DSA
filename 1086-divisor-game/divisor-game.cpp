class Solution {
public:
    // A player wins if they can move to a losing state for the opponent.
    // define the state as : 
    // dp[n] = true --> current player wins
    // dp[n] = false --> current player loses
    // dp[n] = true if ∃ x such that dp[n - x] == false

    bool divisorGame(int n) {
        vector<bool> dp(n + 1, false);
        dp[1] = false;

        for(int i = 2; i <= n; i++) {
            for(int x = 1; x < i; x++) {
                if(i % x == 0 && dp[i - x] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};