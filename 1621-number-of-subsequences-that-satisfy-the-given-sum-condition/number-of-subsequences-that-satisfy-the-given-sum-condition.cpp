class Solution {
public:
    // order matterns in subsequences
    // but here, we are only concerned about mini and maxi in a subseq, so we can sort the array
    // as order doesn't affects the minimum or maximum
    // now we can simply use two pointers, left and right.
    // if we pick two indices left and right (where left <= right), and their sum is valid (nums[left] + nums[right] <= target), then any subsequence that includes nums[left] as its minimum and uses any combination of the numbers between left and right is also valid.
    // For the elements between left and right, we have a choice for each: include it or don't include it. The number of such choices is exactly 2^(right - left).
    // Precompute the powers of 2 in an array of size N, as we need them frequently.
    // If nums[left] + nums[right] <= target, we add 2^(right - left) to our total count. Then we increment left to check the next minimum.
    // If sum > target, then decrease right pointer.

    const int MOD = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // precomputing powers of 2
        vector<int> power(n, 1);
        for(int i = 1; i < n; i++) {
            power[i] = (power[i-1] * 2) % MOD;
        }

        int left = 0, right = n-1;
        int count = 0;

        while(left <= right) {
            if(nums[left] + nums[right] <= target) {
                count = (count + power[right - left]) % MOD;
                left++;
            }
            else right--;
        }

        return count;
    }
};