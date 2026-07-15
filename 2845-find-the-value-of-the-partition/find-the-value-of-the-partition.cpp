class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // sort krne ke baad, hum array ko kisi bhi point se uthake cut kr skte hn. Like: [1, 10, 100]
        // so we just need to find the minimum difference between adjacent elements.
        int mini = INT_MAX;
        for(int i = 0; i < n-1; i++) mini = min(mini, nums[i + 1] - nums[i]);
        return mini;
    }
};