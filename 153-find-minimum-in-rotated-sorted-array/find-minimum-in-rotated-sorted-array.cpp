class Solution {
public:
    // hme minimum dhundna haiii aurr hme pta haii ki rotated sorted array me ek side hmesha sorted rehti haii
    // and we know ki sorted array me se minimum dhundna to easy haii
    // so sorted part me se minimum lete jao aur array ko shrink krte jaoo.
    // at the end, hme minimum mil chuka hoga.

    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = n - 1;
        int ans = INT_MAX;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[low] <= nums[mid]) { // check if sorted
                ans = min(ans, nums[low]);
                low = mid + 1; // elimiate this sorted half
            }
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};