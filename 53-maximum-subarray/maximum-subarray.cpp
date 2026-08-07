class Solution {
public:
    // We will find the maximum subarray sum ending at i, that is, sum[i].
    // we will then take the maximum of all sum[i]

    int maxSubArray(vector<int>& nums) {
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
};