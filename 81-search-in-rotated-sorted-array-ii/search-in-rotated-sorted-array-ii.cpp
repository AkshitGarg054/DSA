class Solution {
public:
    // similar to search in rotated sorted array I
    // the only problem here, that can arise is that, we will not able to recognize the sorted part
    // when we will encounter arr[low] == arr[mid] == arr[high]
    // so we just need to fix this condition
    // as we are already checking arr[mid] == target, so if arr[mid] != target, then arr[low] and arr[high] also not equal to target 
    // so, we can do, low + 1 and high - 1

    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(target == nums[mid]) return true;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++, high--;
                continue;
            }

            // check sorted part
            if(nums[low] <= nums[mid]) {
                if(target >= nums[low] && target < nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
            else {
                if(target > nums[mid] && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }

        return false;
    }
};