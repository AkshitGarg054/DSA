class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = n - 1;
        int ans;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int count = 0;
            for(auto &ele: nums) {
                if(ele <= nums[mid]) count++;
            }

            if(count % 2 != 0) { // if count is odd
                ans = nums[mid];
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};