class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        map<int, bool> mp; // ordered map is needed to maintain the order of numbers from 1 to n
        for(int i = 1; i <= n; i++) mp[i] = false;

        for(int i = 0; i < n; i++) {
            int ele = nums[i];
            if(mp.count(ele)) mp[ele] = true;
        }

        for(auto [key, val]: mp) {
            if(val == false) return key;
        }

        return n + 1;
    }
};