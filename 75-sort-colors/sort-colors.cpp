class Solution {
public:
    // Simply think about where each number should go: 
    // 0 should go at the front, 2 at the back and 1 can stay in the middle.
    // So, let's maintain:
    // left = where the next 0 should be placed.
    // right = where the next 2 should be placed.
    // i = current element we're checking

    void sortColors(vector<int>& nums) {
        int left = 0;
        int i = 0;
        int right = nums.size() - 1;

        while(i <= right) {
            if(nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
                i++; // increment both bcz the element we swapped from left has already been processed
            }
            else if(nums[i] == 1) i++;
            else {
                swap(nums[i], nums[right]);
                right--;
            }
        }
    }
};