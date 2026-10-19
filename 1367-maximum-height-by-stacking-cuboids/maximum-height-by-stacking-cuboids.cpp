class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();

        // sort each cuboid's dimensions --> so, last dimension of each, will become height (that is, the max one)
        for(auto &c : cuboids) {
            sort(c.begin(), c.end());
        }

        // sort all cuboids --> so, last cuboid will become base as it will be having largest dimensions
        sort(cuboids.begin(), cuboids.end());

        // using LIS approach
        vector<int> dp(n); // dp[i] represents the maximum total height of a stack with cuboid i as the bottom cuboid.
        for(int i = 0; i < n; i++) dp[i] = cuboids[i][2]; // base case --> height of curr cuboid
        
        for(int i = 0; i < n; i++) {
            auto base = cuboids[i];
            for(int j = 0; j < i; j++) {
                auto curr = cuboids[j];

                if(curr[0] <= base[0] && curr[1] <= base[1] && curr[2] <= base[2]) {
                    if(dp[j] + base[2] > dp[i]) {
                        dp[i] = dp[j] + base[2];
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};