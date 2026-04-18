class Solution {
public:
    int n;
    vector<int> dp;

    bool solve(int index, vector<int> &nums) {
        if(index == n) return true;
        if(dp[index] != -1) return dp[index];

         // case 1: two equal
        if(index + 1 < n && nums[index] == nums[index + 1]) {
            if(solve(index + 2, nums)) return dp[index] = true;
        }

        // case 2: three equal
        if(index + 2 < n && nums[index] == nums[index + 1] && nums[index + 1] == nums[index + 2]) {
            if(solve(index + 3, nums)) return dp[index] = true;
        }

        // case 3: consecutive
        if(index + 2 < n && nums[index] + 1 == nums[index + 1] && nums[index + 1] + 1 == nums[index + 2]) {
            if(solve(index + 3, nums)) return dp[index] = true;
        }

        return dp[index] = false;
    }

    bool validPartition(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, -1);
        return solve(0, nums);
    }
};