class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        
        // step 1
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        if(index == -1) {
            sort(nums.begin(), nums.end());
            return;
        }

        // step 2
        int desired = nums[index + 1];
        int desired_index = index + 1;

        for(int i = n-1; i >= index + 2; i--) {
            if(nums[i] > nums[index]) {
                desired = nums[i];
                desired_index = i;
                break;
            }
        }

        // step 3
        swap(nums[index], nums[desired_index]);

        // step 4
        reverse(nums.begin() + index + 1, nums.end());
    }
};