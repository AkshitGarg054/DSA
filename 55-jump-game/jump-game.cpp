class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();    
        int limit = 0 + nums[0];

        int i = 0; 
        while(i <= limit && i < n) {
            if(i + nums[i] > limit) {
                limit = i + nums[i];
            }

            if(limit >= n-1) return true;
            i++;
        }

        return false;
    }
};