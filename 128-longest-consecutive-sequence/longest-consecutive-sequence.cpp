class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        unordered_map<int, bool> mp;
        for(auto ele : nums) mp[ele] = false; // store all elements in a map

        int maxi = 1;

        for(int i = 0; i < n; i++) {
            int ele = nums[i];
            if(mp[ele] == true) continue;

            mp[ele] = true;
            int count = 1;

            int temp = ele;
            while(mp.count(temp - 1) && !mp[temp - 1]) {
                count++;
                mp[temp - 1] = true;
                temp--;
            }

            temp = ele;
            while(mp.count(temp + 1) && !mp[temp + 1]) {
                count++;
                mp[temp + 1] = true;
                temp++;
            }

            maxi = max(maxi, count);
        } 

        return maxi;
    }
};