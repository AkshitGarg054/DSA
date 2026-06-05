class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(auto it : nums) mp[it]++;

        int maxi = INT_MIN;
        int ans = -1;
        for(auto [key, value] : mp) {
            if(value > maxi) {
                maxi = value;
                ans = key;
            }
        }

        return ans;
    }
};