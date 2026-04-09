class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end()) + k;

        map<int, int> diff; // map --> it must be ordered
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            int ele = nums[i];
            mp[ele]++;

            int l = max(0, ele - k);
            int r = min(maxi, ele + k);

            diff[l]++;
            diff[r + 1]--;
            diff[ele] += 0;
        }

        int ans = 1;
        int prev_sum = 0;

        for(auto &[key, val] : diff) {
            int ele = key;
            int count = val + prev_sum;
            
            int required_ops = count - mp[ele];
            int valid = min(required_ops, numOperations);
            ans = max(ans, valid + mp[ele]);

            prev_sum = count;
        }

        return ans;
    }
};