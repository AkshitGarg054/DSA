class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0, r = 0;
        int max_len = 0; 
        long long curr_sum = 0;

        while(r < n) {
            curr_sum += nums[r];
            long long target_sum = 1LL * nums[r] * (r - l + 1);

            while(target_sum - curr_sum > k) {
                curr_sum -= nums[l];
                l++;
                target_sum -= nums[r]; // updating target sum
            }

            max_len = max(max_len, r - l + 1);
            r++;
        }

        return max_len;
    }
};