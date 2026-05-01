class Solution {
public:
    // See, hmne pehle ek question kra hua haii jisme hm sorted half dhundte the.
    // But here, as we want the minimum element, so minimum can lie either in the unsorted half or it is the first element of the sorted half

    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low < high) { // loop will stop when low == high (that is, only one element will left)
            int mid = low + (high - low) / 2;
            
            if(nums[mid] < nums[high]) high = mid; // min can either be nums[mid] or it can be present in unsorted half
            else if(nums[mid] > nums[high]) low = mid + 1; // as mid value is greater than high, so mid can't be min.
            else high--; // duplicate handling --> shrink window
        }

        return nums[low]; // or nums[high]
    }
};