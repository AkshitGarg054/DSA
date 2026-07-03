class Solution {
public:
    // {4, 5, 1, 2, 3, 7, 6, 8}
    // k = 3 --> [3], [3, 7], [2, 3, 7] 

    // {2, 5, 1, 4, 3, 6}
    // k = 1 --> [1], [1, 4], [5, 1](after sorting) 
    // If a subarray has x smaller numbers than k, and x bigger number OR (x + 1) bigger numbers
    // then we are confirmed that after sorting the array, k will be the median.
    // we can extend any amount to the left and any amount to the right independently, or extend both left and right.

    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int pos = -1;

        for(int i = 0; i < n; i++) {
            if(nums[i] == k) {
                pos = i;
                break;
            }
        }

        unordered_map<int, int> mp; // stores the freq of different left sums
        int sum = 0;

        for(int i = pos; i >= 0; i--) {
            if(nums[i] > k) sum += 1;
            else if(nums[i] < k) sum -= 1;
            mp[sum]++;
        }

        int ans = 0;
        sum = 0;

        for(int i = pos; i < n; i++) {
            if(nums[i] > k) sum += 1;
            else if(nums[i] < k) sum -= 1;

            // we want the total subarray sum to be either 0 or 1.
            // left_sum = 0 - right_sum
            // left_sum = 1 - right_sum
            ans += mp[-sum];
            ans += mp[1 - sum];
        }

        return ans;
    }
};