class Solution {
public:
    // abs(even - odd) = always odd 
    // so, when our nums1 have both odd and even elements, then we can only make nums2 to be all odd
    // odd elements ki position pe odd rakhdo aurr even elements ki position pe (even - odd) krdo
    // and we want (even - odd) >= 1 for every even --> therefore, just check for min_even. 
    // Check whether min_even - min_odd >= 1 or not (as we can choose odd to be any odd, but even is fixed to be nums[i])

    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int min_even = INT_MAX;
        int min_odd = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(nums1[i] % 2 != 0) min_odd = min(min_odd, nums1[i]);
            if(nums1[i] % 2 == 0) min_even = min(min_even, nums1[i]);
        }

        if(min_even == INT_MAX || min_odd == INT_MAX) return true; // whole array is either odd or even
        if(min_even > min_odd) return true; 
        return false;
    }
};