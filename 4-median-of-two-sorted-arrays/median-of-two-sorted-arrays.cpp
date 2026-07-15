class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;
        int mid = total / 2;

        // if total is even, then we want (mid - 1) and (mid) element.
        // if total is odd, then we want (mid) element.
        int count = 0;
        int ele1, ele2;

        int i = 0, j = 0;
        while(i < n && j < m) {
            int curr;
            if(nums1[i] <= nums2[j]) curr = nums1[i++];
            else if(nums1[i] > nums2[j]) curr = nums2[j++];

            if(count == mid - 1) ele1 = curr;
            if(count == mid) ele2 = curr;
            count++;
        }

         while (i < n) {
            int curr = nums1[i++];
            if (count == mid - 1) ele1 = curr;
            if (count == mid) ele2 = curr;
            count++;
        }

        while (j < m) {
            int curr = nums2[j++];
            if (count == mid - 1) ele1 = curr;
            if (count == mid) ele2 = curr;
            count++;
        }

        double median;
        if(total % 2 == 0) median = (ele1 + ele2) / 2.0;
        else median = ele2;

        return median;
    }
};