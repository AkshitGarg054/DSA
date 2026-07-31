class Solution {
public:
    // array also contains -ve elements, so normal sliding window won't work
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        mp[0] = 1; // for subarrays starting from index 0

        int sum = 0;
        int count = 0;

        for(auto &ele: nums) {
            sum += ele;

            int target = sum - k;
            if(mp.count(target)) count += mp[target];

            mp[sum]++;
        }

        return count;
    }
};