class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        int low = 0, high = n - 1;
        int ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(mid == 0 && nums[mid] > nums[mid + 1] || mid == n - 1 && nums[mid] > nums[mid - 1]) return mid;
            else if(mid > 0 && mid + 1 < n && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            else if(mid > 0 && nums[mid] < nums[mid - 1]) high = mid - 1;
            else low = mid + 1;
        }

        return -1;
    }
};