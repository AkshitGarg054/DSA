class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = 0, j = 0;
        vector<int> merged;

        while(i < n && j < m) {
            if(nums1[i] < nums2[j]) merged.push_back(nums1[i++]);
            else if(nums2[j] < nums1[i]) merged.push_back(nums2[j++]);
            else {
                merged.push_back(nums1[i]);
                merged.push_back(nums2[j]);
                i++, j++;
            }
        }

        while(i < n) merged.push_back(nums1[i++]);
        while(j < m) merged.push_back(nums2[j++]);

        int sz = merged.size();
        int mid = sz / 2;
        double median;

        if(sz % 2 == 0) median = (merged[mid - 1] + merged[mid]) / 2.0;
        else median = merged[mid];

        return median;
    }
};