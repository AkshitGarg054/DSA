class Solution {
public:
    int first(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                ans = mid;
                high = mid - 1; // keep searcing left
            }
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return ans;
    }

    int last(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                ans = mid;
                low = mid + 1; // keep searcing right
            }
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2, -1);

        ans[0] = first(nums, target);
        ans[1] = last(nums, target);
        return ans;
    }
};