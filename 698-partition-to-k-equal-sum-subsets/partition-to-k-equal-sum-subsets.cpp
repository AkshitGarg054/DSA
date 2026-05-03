class Solution {
public:
    int n;
    vector<int> dp; // again, here also, only 'mask' will be the dp state. (it takes into account, other things also)

    int solve(int mask, int sum, vector<int> &nums, int target, int k) {
        if(k == 1) return true;
        if(sum == target) return solve(mask, 0, nums, target, k - 1);
        if(dp[mask] != -1) return dp[mask];

        for(int i = 0; i < n; i++) {
            if(!(mask & (1 << i))) { // if ith index is not vis

                if(sum + nums[i] <= target) {
                    if(solve(mask | (1 << i), sum + nums[i], nums, target, k)) return dp[mask] = true;
                }
            }
        }

        return dp[mask] = false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();

        int sum = 0;
        for(auto ele : nums) sum += ele;
        if(sum % k != 0) return false; 

        int target = sum / k;
        sort(nums.rbegin(), nums.rend()); // sort in descending
        if(nums[0] > target) return false; 

        dp.resize(1 << n, -1);
        return solve(0, 0, nums, target, k); // mask, sum
    }
};