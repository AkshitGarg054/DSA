class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        sort(nums.begin(), nums.end());

        int len = 1;
        int maxi = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1]) continue;
            else if(nums[i] == nums[i - 1] + 1) len++;
            else {
                maxi = max(maxi, len);
                len = 1;
            }
        }

        maxi = max(maxi, len);
        return maxi;
    }
};