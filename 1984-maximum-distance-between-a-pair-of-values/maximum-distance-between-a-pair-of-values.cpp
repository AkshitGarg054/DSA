class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
           int x = nums1[i];

            int low = i, high = m-1;
            int index = -1;
            
            while(low <= high) {
                int mid = low + (high - low) / 2;

                if(nums2[mid] >= nums1[i]) {
                    index = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }

            if(index == -1) continue;
            maxi = max(maxi, index - i);
        }

        if(maxi == INT_MIN) return 0;
        return maxi;
    }
};