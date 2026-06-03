class Solution {
public:
    // generally, we start the pointers from beginning.
    // But here, if we start from beginning, then everytime we need to shift the elements of nums1 forward.
    // instead, we can see that we have an extra space at the end of nums1
    // so we will start the pointers from backward and keep building the sorted array

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = n + m - 1;

        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                k--, i--;
            }
            else {
                nums1[k] = nums2[j];
                k--, j--;
            }
        }

        // if j is still left
        while(j >= 0) {
            nums1[k] = nums2[j];
            k--, j--;
        }
    }
};