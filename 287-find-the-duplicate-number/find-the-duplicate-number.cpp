class Solution {
public:
    // approach 2: going to arr[i] position and replacing the ele at that pos with -ve sign

    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int pos = abs(nums[i]);

            if(nums[pos] < 0) return abs(nums[i]);
            else nums[pos] = -nums[pos];            
        }
        
        return -1;
    }
};