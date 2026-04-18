class Solution {
public:
    // In this question, we require 3D DP for recursion + memo approach --> it will give MLE.
    // we will use some other smart approach.
    // we know, min_count(left + right) = x
    // remaining middle part = total_sum - x;
    // find the longest subarray whose sum = totl_sum - x;
    // subarray haii, so we can apply sliding window.

    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total_sum = 0;
        for(auto num : nums) total_sum += num;

        int target = total_sum - x;
        if(target < 0) return -1;

        int l = 0, r = 0;
        int sum = 0;
        int max_len = INT_MIN;

        while(r < n) {
            sum += nums[r];

            while(sum > target) {
                sum -= nums[l];
                l++;
            }

            if(sum == target) max_len = max(max_len, r - l + 1);
            r++;
        }

        if(max_len == INT_MIN) return -1;
        return n - max_len;
    }
};