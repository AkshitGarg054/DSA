class Solution {
public:
    int N;
    vector<vector<int>> dp;

    int solve(int index, int target, vector<int> &nums) {
        if(target == 0) return 0;
        if(index == nums.size()) return INT_MAX;
        if(dp[index][target] != -1) return dp[index][target];

        // there is no need to reuse powers,
        // using the same power twice is never optimal.
        // If you subtract 2^k twice, that's the same as subtracting 2^(k+1) once

        int sub = INT_MAX;
        if(nums[index] <= target) { 
            int res = solve(index + 1, target - nums[index], nums);
            if(res != INT_MAX) sub = 1 + res;
        }

        int add = INT_MAX;
        if(target + nums[index] <= 2*N) {
            int res = solve(index + 1, target + nums[index], nums);
            if(res != INT_MAX) add = 1 + res;
        }

        int skip = solve(index + 1, target, nums);
        
        return dp[index][target] = min({sub, add, skip});
    }

    int minOperations(int n) {
        N = n;
        vector<int> vec;
        for(int i = 0; pow(2, i) <= 2*n; i++) { // extend the range for "add" operation, to one extra power
            int num = pow(2, i);
            vec.push_back(num);
        }

        dp.assign(vec.size(), vector<int>(2*n + 1, -1));
        return solve(0, n, vec);
    }
};