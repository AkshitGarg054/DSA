class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // step 1: Find the first index i from the right such that nums[i] < nums[i + 1]
        int index = -1;
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

        // step 2: Now, find the rightmost element greater than nums[i] in the suffix
        int ele = nums[index];
        int desired = nums[index + 1];
        int desired_index = index + 1;

        for(int i = n - 1; i >= index + 2; i--) {
            if(nums[i] > ele) {
                desired = nums[i];
                desired_index = i;
                break;
            }
        }

        // step 3: swap them
        swap(nums[index], nums[desired_index]);

        // reverse the suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};