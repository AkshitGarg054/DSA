class Solution {
public:
    // can we split the array such that the sum of each subarray does not exceed 'mid'
    bool check(int mid, vector<int> &nums, int k) {
        int parts = 1;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > mid) return false;
            if(sum + nums[i] <= mid) sum += nums[i];
            else if(sum + nums[i] > mid) {
                parts++;
                sum = nums[i];
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX; // we need the minimum largest sum

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(check(mid, nums, k)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};