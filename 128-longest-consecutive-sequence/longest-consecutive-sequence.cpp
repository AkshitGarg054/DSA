class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        map<int, bool> mp;
        for(auto &ele: nums) mp[ele] = true;
        
        auto it = mp.begin();
        auto [val, found] = *it;

        int prev = val;
        int maxi = 1;
        int len = 1;

        it++;
        while(it != mp.end()) {
            auto [val, found] = *it;

            if(val == prev + 1) {
                len++;
                maxi = max(maxi, len);
            }
            else len = 1;

            prev = val;
            it++;
        }

        return maxi;
    }
};