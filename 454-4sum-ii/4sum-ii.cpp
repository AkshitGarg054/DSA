class Solution {
public:
    // whenever koi sum find krna ho arrays me, then always think of looking previously stored values in map
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> mp;

        for(auto &a: nums1) {
            for(auto &b: nums2) mp[a + b]++;
        }

        int count = 0;

        for(auto &c: nums3) {
            for(auto &d: nums4) {
                int target = -(c + d);
                if(mp.count(target)) count += mp[target];
            }
        }

        return count;
    }
};