class Solution {
public:
    bool check(int mid, vector<int> &nums, int k) {
        int n = nums.size();
        int sum = 0, parts = 1;

        for(int i = 0; i < n; i++) {
            if(nums[i] > mid) return false;
            if(sum + nums[i] <= mid) sum += nums[i];
            else {
                parts++;
                if(parts > k) return false;
                sum = nums[i];
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

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