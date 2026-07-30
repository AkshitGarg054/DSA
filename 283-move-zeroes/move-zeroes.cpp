class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int i = -1, j = -1; // i -> first zero, j -> first ele after zero which is != 0
        for(int index = 0; index < n; index++) {
            if(nums[index] == 0) {
                i = index;
                break;
            }
        }

        if(i == -1) return;

        for(int index = i + 1; index < n; index++) {
            if(nums[index] != 0) {
                j = index;
                break;
            }
        }

        if(j == -1) return;

        while(j < n) {
            if(nums[j] == 0) j++;
            else swap(nums[i++], nums[j++]);
        }
    }
};