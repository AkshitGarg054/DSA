class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int duplicate = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int count = 0;
            for(auto &num: nums) {
                if(num <= mid) count++;
            }

            if(count > mid) {
                duplicate = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return duplicate;
    }
};