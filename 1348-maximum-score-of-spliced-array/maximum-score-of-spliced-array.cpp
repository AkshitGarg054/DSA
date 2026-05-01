class Solution {
public:
    // Instead of swapping explicitly, what is the gain if I swap i subarray.
    // If you swap [l..r], then gain for nums1 = (nums2[i] - nums1[i]) over i in [l..r]
    // So, define diff[i] = nums2[i] - nums1[i]
    // Now, problem becomes : find subarray with maximum sum in diff[]
    // That is, kadane algo

    int kadane(vector<int> &arr) {
        int sum = 0, maxi = INT_MIN;
        
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            maxi = max(maxi, sum);
            if(sum < 0) sum = 0;
        }

        return maxi;
    }

    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        vector<int> diff1(n), diff2(n); // basically profit

        for(int i = 0; i < n; i++) {
            diff1[i] = nums2[i] - nums1[i]; // gain if we swap into nums1
            diff2[i] = nums1[i] - nums2[i]; // gain if we swap into nums2
        }

        int max_gain1 = kadane(diff1); // using the subarray of nums2 into nums1
        int max_gain2 = kadane(diff2);

        return max(sum1 + max_gain1, sum2 + max_gain2);
    }
};