class Solution {
public:
    // BITMASKING :
    // To check if ith element is chosen or not : (mask & (1 << i))
    // To mark the ith element as chosen : (mask | (1 << i))
    // we didn't take op as the dp state coz mask itself is storing the value of ops

    vector<int> dp;
    int n, m;

    int solve(int mask, int ops, vector<int> &nums) {
        if(ops > n) return 0; // we can only do n operations
        if(dp[mask] != -1) return dp[mask];

        int ans = INT_MIN;
        
        for(int i = 0; i < m; i++) {
            if(mask & (1 << i)) continue; // if already taken
            
            for(int j = i + 1; j < m; j++) {
                if(mask & (1 << j)) continue; // if already taken

                int newMask = mask | (1 << i) | (1 << j); // mark both visited
                int score = ops * __gcd(nums[i], nums[j]) + solve(newMask, ops + 1, nums); 
                ans = max(ans, score);
            }
        }

        return dp[mask] = ans;
    }

    int maxScore(vector<int>& nums) {
        m = nums.size();
        n = nums.size() / 2;

        dp.resize(1 << 14, -1);
        return solve(0, 1, nums); // mask, ops
    }
};