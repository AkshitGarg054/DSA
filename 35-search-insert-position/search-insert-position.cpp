class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) {
                ans = mid + 1;
                low = mid + 1;
            }
            else {
                ans = mid;
                high = mid - 1;
            }
        }

        if(ans == -1) return 0;
        return ans;
    }
};