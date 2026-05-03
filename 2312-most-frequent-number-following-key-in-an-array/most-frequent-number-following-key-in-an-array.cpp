class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            if(nums[i] == key && i < n-1) {
                mp[nums[i + 1]]++;
            }
        }

        int maxi_freq = 0;
        int ans = -1;

        for(auto [num, freq] : mp) {
            if(freq > maxi_freq) {
                maxi_freq = freq;
                ans = num;
            }
        }

        return ans;
    }
};