class Solution {
public:
    vector<vector<int>> dp;
    unordered_map<int, int> mp;

    int solve(int index, int prev, vector<int> &stones) {
        if(index == stones.size() - 1) return true;
        if(dp[index][prev] != -1) return dp[index][prev];

        // prev - 1
        if(prev - 1 > 0) {
            int next_pos = stones[index] + prev - 1;

            if(mp.count(next_pos)) {
                int idx = mp[next_pos];
                if(solve(idx, prev - 1, stones)) return dp[index][prev] = true;
            }
        }   

        // prev
        int next_pos = stones[index] + prev;

        if(mp.count(next_pos)) {
            int idx = mp[next_pos];
            if(solve(idx, prev, stones)) return dp[index][prev] = true;
        }  

        // prev + 1
        next_pos = stones[index] + prev + 1;

        if(mp.count(next_pos)) {
            int idx = mp[next_pos];
            if(solve(idx, prev + 1, stones)) return dp[index][prev] = true;
        }  

        return dp[index][prev] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones.size() < 2 || stones[1] != 1) return false; 

        for(int i = 0; i < n; i++) mp[stones[i]] = i;

        dp.assign(n, vector<int>(n + 1, -1));
        return solve(1, 1, stones); // position, prev_jump_size
    }
};


// 0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17
// .  .     .     .  .     .             .                   .

// next_pos = stones[index] + (prev - 1)
// next_pos = stones[index] + (prev)
// next_pos = stones[index] + (prev + 1)

// find the index of next_pos
// To find the index, we can either use a map or lower_bound()
