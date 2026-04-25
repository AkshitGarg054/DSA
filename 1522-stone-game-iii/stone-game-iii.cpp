class Solution {
public:
    int n;
    vector<int> dp;

    // this is recursive + memo code
    int solve(int index, vector<int> &nums) {
        if(index == n) return 0;
        if(dp[index] != INT_MAX) return dp[index];

        int takeOne = nums[index] - solve(index + 1, nums); // alice - (bob - alice) = all alice get added and bobs get subtracted
        
        int takeTwo = INT_MIN;
        if(index + 1 < n) takeTwo = nums[index] + nums[index + 1] - solve(index + 2, nums);

        int takeThree = INT_MIN;
        if(index + 2 < n) takeThree = nums[index] + nums[index + 1] + nums[index + 2] - solve(index + 3, nums);

        return dp[index] = max({takeOne, takeTwo, takeThree});
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();

        // int diff = solve(0, stoneValue); // maximize the difference (alice - bob)
        // if(diff > 0) return "Alice";
        // else if(diff < 0) return "Bob";
        // return "Tie";

        dp.resize(n + 1, 0);

        // This is tabulation code (bottom up)
        for(int i = n-1; i >= 0; i--) {
            int takeOne = stoneValue[i] - dp[i + 1];
            
            int takeTwo = INT_MIN;
            if(i + 1 < n) takeTwo = stoneValue[i] + stoneValue[i + 1] - dp[i + 2];

            int takeThree = INT_MIN;
            if(i + 2 < n) takeThree = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3];

            dp[i] = max({takeOne, takeTwo, takeThree});
        }

        int value = dp[0];
        if(value > 0) return "Alice";
        else if(value < 0) return "Bob";
        return "Tie";
    }
};