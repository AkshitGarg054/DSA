class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0, r = 0;
        int count_ones = 0;
        int maxi = INT_MIN;

        while(r < n) {
            if(nums[r] == 1) count_ones++;

            while((r - l + 1) - count_ones > k) {
                if(nums[l] == 1) count_ones--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};