class Solution {
public:
    // As we have only three categories, so let's keep only three types of elements (0, 1 and 2).
    // we need the final array as: [0, 0, 0, ...1, 1, 1, ....2, 2, 2, ...]
    // Min adjacent swaps = count inversions
    // The minimum number of adjacent swaps needed equals exactly the number of inversions in the category array.
    // But we don't care about the inversion in between a category.
    // As we have only three different values, so let's keep a running count for 1 and 2.
    // Scan left to right:
    // If category == 0: it needs to jump over every 1 and 2 seen before it -> add count1 + count2.
    // If category == 1: it needs to jump over every 2 seen before it -> add count2.
    // If category == 2: contributes 0 

    const int MOD = 1e9 + 7;
        
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        long long count1 = 0, count2 = 0;
        long long ans = 0;

        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            if(nums[i] < a) arr[i] = 0;
            else if(nums[i] >= a && nums[i] <= b) arr[i] = 1;
            else if(nums[i] > b) arr[i] = 2;
        }

        for(int x: arr) {
            if(x == 0) ans = (ans + count1 + count2) % MOD;
            else if(x == 1) {
                ans = (ans + count2) % MOD;
                count1++;
            }
            else count2++;
        }

        return (int)ans;
    }
};