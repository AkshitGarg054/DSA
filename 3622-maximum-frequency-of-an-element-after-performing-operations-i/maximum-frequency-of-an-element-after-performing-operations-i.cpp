class Solution {
public:
    // For any number 'a', if any element is from (a - k, a + k) ...we can convert it to 'a'.
    // So, for every ele in nums, we will check how many elements we can converge to that ele.
    // Brute force will take O(n^2)
    // To optimize it, we will create a freq vector which will store the freq of each ele.
    // size of freq vector = value of maximum element in nums
    // and to get the count of numbers in the range (l, r), we can do freq[r] - freq[l - 1] (in prefix sum array)

    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxi + 1, 0);
        for(auto ele : nums) freq[ele]++;

        // take cumulative sum
        for(int i = 1; i <= maxi; i++) freq[i] += freq[i-1];

        int ans = 1;

        // we can't loop from i = 0 to n, because the maximum freq element can also be the one, which does not even exists in nums array
        // for example : nums = [88, 53], k = 27, numOperations = 2 (In this case, answer = 2, and maxi freq element is neither 88 nor 53)
        for(int ele = 1; ele <= maxi; ele++) {
            int curr_freq = freq[ele] - freq[ele - 1]; // cumulative sum le liya na, so freq[ele - 1] subtract krna pdega
            int r = min(maxi, ele + k);
            int l = max(0, ele - k);

            long long total_count = freq[r] - ((l > 0) ? freq[l - 1] : 0);
            int required_operations = total_count - curr_freq;

            int valid = min(numOperations, required_operations);
            ans = max(ans, curr_freq + valid);
        }

        return ans;
    }
};