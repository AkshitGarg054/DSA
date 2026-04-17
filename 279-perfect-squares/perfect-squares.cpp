class Solution {
public:
    vector<vector<int>> dp;

    int solve(int index, int sum, vector<int> &squares, int target) {
        if(sum == target) return 0;
        if(index == squares.size()) return 1e9;
        if(dp[index][sum] != -1) return dp[index][sum];

        int take = INT_MAX;
        if(sum + squares[index] <= target) take = 1 + solve(index, sum + squares[index], squares, target);
        int skip = solve(index + 1, sum, squares, target);

        return dp[index][sum] = min(take, skip);
    }
 
    int numSquares(int n) {
        vector<int> squares;
        for(int i = 1; i*i <= n; i++) squares.push_back(i*i);

        dp.assign(squares.size(), vector<int>(n + 1, -1));
        return solve(0, 0, squares, n);
    }
};