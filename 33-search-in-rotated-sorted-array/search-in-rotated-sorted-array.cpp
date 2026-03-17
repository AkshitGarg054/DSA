class Solution {
public:
    // in this question, one half will always be sorted, and we just need to find out which half is sorted

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(target == nums[mid]) return mid;
            
            // check which half is sorted
            // if left sorted
            if(nums[low] <= nums[mid]) {
                if(target >= nums[low] && target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
            else if(nums[mid] <= nums[high]) { // if right sorted
                if(target > nums[mid] && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }

        return -1;
    }
};