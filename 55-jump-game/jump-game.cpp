class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int limit = nums[0];

        int i = 1;
        while(i <= limit) {
            limit = max(limit, i + nums[i]);
            if(limit >= n-1) return true;
            i++;
        }

        return false;
    }
};