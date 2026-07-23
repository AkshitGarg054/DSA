class Solution {
public:
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