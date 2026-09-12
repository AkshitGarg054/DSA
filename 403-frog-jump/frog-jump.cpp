class Solution {
public:
    vector<vector<int>> dp;

    int solve(int index, int prev, vector<int> &stones) {
        if(index == stones.size() - 1) return true;
        if(dp[index][prev] != -1) return dp[index][prev];

        // prev - 1
        if(prev - 1 > 0) {
            int next_pos = stones[index] + prev - 1;

            int lb = lower_bound(stones.begin(), stones.end(), next_pos) - stones.begin();
            if(lb != stones.size() && stones[lb] == next_pos) {
                if(solve(lb, prev - 1, stones)) return dp[index][prev] = true;
            }
        }   

        // prev
        int next_pos = stones[index] + prev;

        int lb = lower_bound(stones.begin(), stones.end(), next_pos) - stones.begin();
        if(lb != stones.size() && stones[lb] == next_pos) {
            if(solve(lb, prev, stones)) return dp[index][prev] = true;
        }  

        // prev + 1
        next_pos = stones[index] + prev + 1;

        lb = lower_bound(stones.begin(), stones.end(), next_pos) - stones.begin();
        if(lb != stones.size() && stones[lb] == next_pos) {
            if(solve(lb, prev + 1, stones)) return dp[index][prev] = true;
        }  

        return dp[index][prev] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones.size() < 2 || stones[1] != 1) return false; 

        dp.assign(n, vector<int>(n + 1, -1));
        return solve(1, 1, stones); // position, prev_jump_size
    }
};