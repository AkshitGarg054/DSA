class Solution {
public:
    int kadane_min(vector<int> &nums) {
        int n = nums.size();
        int mini = nums[0];
        int prev = nums[0], curr = nums[0];

        for(int i = 1; i < n; i++) {
            curr = min(nums[i], prev + nums[i]);
            mini = min(mini, curr);
            prev = curr;
        }

        return mini;
    }

    int kadane_max(vector<int> &nums) {
        int n = nums.size();
        int maxi = nums[0];
        int prev = nums[0], curr = nums[0];

        for(int i = 1; i < n; i++) {
            curr = max(nums[i], prev + nums[i]);
            maxi = max(maxi, curr);
            prev = curr;
        }

        return maxi;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);
        int maxi = kadane_max(nums);
        int mini = kadane_min(nums);
        int maxi_circular = total - mini;

        if(maxi > 0) return max(maxi, maxi_circular);
        return maxi;
    }
};