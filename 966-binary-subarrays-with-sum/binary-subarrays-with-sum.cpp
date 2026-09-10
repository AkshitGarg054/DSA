class Solution {
public:
    int numArrays(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0;
        int count = 0;

        while(r < n) {
            sum = sum + nums[r];

            while (sum > k) {
                sum = sum - nums[l];
                l++;
            }

            count += (r - l + 1);
            r++;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numArrays(nums, goal) - numArrays(nums, goal - 1);
    }
};