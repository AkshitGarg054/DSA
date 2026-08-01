class Solution {
public:
    // we need to find the max length of subarray that we can choose with the limit of k operations.
    // we will find the actual sum and the expected sum for each window.
    // each element can be incremented till the max element in a window.
    // we can sort the array to handle the maximum thing.

    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0, r = 0;
        int len = 0;
        long long actual = 0;

        while(r < n) {
            actual += nums[r];
            long long expected = 1LL * nums[r] * (r - l + 1);

            while(expected - actual > k) {
                actual -= nums[l];
                expected -= nums[r];
                l++;
            }

            len = max(len, r - l + 1);
            r++;
        }

        return len;
    }
};