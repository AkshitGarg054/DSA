class Solution {
public:
    // here, we also have duplicates.
    // eg: nums = [1, 0, 1, 1, 1], target = 0
    // low = 0, high = 4 ---> mid = 2
    // The first condition will see that nums[low] <= nums[mid] = 1, and assume that left half is sorted but it's not.
    // So, it is impossbile to determine the sorted half with this search space.
    // So, we need to shrink the search space by adding one extra condition.

    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return true;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++, high--;
                continue;
            }

            if(nums[low] <= nums[mid]) { // left half is sorted
                if(nums[low] <= target && nums[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
            else {
                if(nums[mid] < target && nums[high] >= target) low = mid + 1;
                else high = mid - 1;
            }
        }

        return false;
    }
};