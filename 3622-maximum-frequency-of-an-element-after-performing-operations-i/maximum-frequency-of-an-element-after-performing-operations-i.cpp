class Solution {
public:
    // DAT approach

    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end()) + k;

        vector<int> diff(maxi + 2, 0);
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            int ele = nums[i];
            mp[ele]++;

            int l = max(0, ele - k);
            int r = min(maxi, ele + k);

            diff[l]++;
            diff[r + 1]--;
        }

        // take cumulative sum of diff array
        for(int i = 1; i < diff.size(); i++) diff[i] += diff[i - 1];

        int ans = 1;

        for(int ele = 1; ele <= maxi; ele++) {
            int required_ops = diff[ele] - mp[ele];
            int valid = min(required_ops, numOperations);
            ans = max(ans, valid + mp[ele]);
        }

        return ans;
    }
};