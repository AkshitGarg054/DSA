class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1; // we need the first element of each group, so skip i = 0
        int count = 1;
        int val = nums[0];

        for(int j = 0; j < n; j++) {
            if(nums[j] != val) {
                val = nums[j]; // val needs to be updated before swapping
                swap(nums[i], nums[j]);
                i++;
                count++;
            }
        }
        
        return count;
    }
};