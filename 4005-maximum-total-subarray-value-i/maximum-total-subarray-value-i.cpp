class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, (long long)nums[i]);
            mini = min(mini, (long long)nums[i]);
        }

        long long ans = 1LL * k * (maxi - mini);
        return ans;
    }
};