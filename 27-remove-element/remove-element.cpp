class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0; // we will keep incrementing i and it will stop at the ele equal to 'val' for swapping
        int count = 0;

        for(int j = 0; j < n; j++) {
            if(nums[j] != val) {
                swap(nums[i], nums[j]);
                i++;
                count++;
            }
        }

        return count;
    }
};