class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int required = (n / 2) + 1;
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            int curr = nums[i];
            mp[curr]++;
            if(mp[curr] >= required) return curr;
        }

        return -1;
    }
};