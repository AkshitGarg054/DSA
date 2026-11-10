class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int limit = nums[0];
        int maxi = nums[0];
        int jumps = 0;

        int i = 1;
        while(i < n) {
            int j = i;
            while(j < n && j <= limit) {
                maxi = max(maxi, j + nums[j]);
                j++;
            }

            i = limit + 1;
            limit = maxi;
            jumps++;
        }

        return jumps;
    }
};