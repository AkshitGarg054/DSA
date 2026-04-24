class Solution {
public:
    // int solve(int l, int r, vector<int> &nums) {
    //     if(l == r) return nums[l];

    //     int pick_left = nums[l] + solve(l + 1, r, nums);
    //     int pick_right = nums[r] + solve(l, r - 1, nums);

    //     return max(pick_left, pick_right);
    // }

    // bool predictTheWinner(vector<int>& nums) {
    //     int n = nums.size();
        
    //     int sum = 0;
    //     for(auto x : nums) sum += x;

    //     int player1 = solve(0, n - 1, nums); // try to get the maximum score for player1
    //     int player2 = sum - player1;

    //     if(player1 >= player2) return true;
    //     return false;
    // }

    // In above code, both players are trying to maximize Player 1’s score.
    // But actually, Player 1 -> maximize score  , Player 2 -> minimize Player 1’s score
    // This is a mini-max (game) DP problem
    // Instead of tracking absolute maximum, track : score difference = (current player score - opponent score)

    int dp[21][21];

    int solve(int l, int r, vector<int> &nums) {
        if(l == r) return nums[l];
        if(dp[l][r] != -1) return dp[l][r];

        // after picking a number, the opponent will play optimally, so we are subtracting.
        int pick_left = nums[l] - solve(l + 1, r, nums); 
        int pick_right = nums[r] - solve(l, r - 1, nums);

        return dp[l][r] = max(pick_left, pick_right);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));

        // solve function returns (score_current_player - score_opponent)
        int scoreDiff = solve(0, n - 1, nums); 
        return scoreDiff >= 0;
    }
};