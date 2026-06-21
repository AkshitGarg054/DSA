class Solution {
public:
    // approach 3: using hashmap and tracking the maximum value
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int maxi = INT_MIN;

        for(auto x: nums) {
            x = abs(x);
            maxi = max(maxi, x);
            mp[x]++;
        }

        vector<int> ans;

        for(int val = 0; val <= maxi; val++) {
            if(!mp.count(val)) continue;

            while(mp[val] > 0) {
                ans.push_back(val * val);
                mp[val]--;
            }
        }

        return ans;
    }
};