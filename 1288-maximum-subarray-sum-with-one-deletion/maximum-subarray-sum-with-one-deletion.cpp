class Solution {
public:
    // For every index i, we can find the maximum subarray sum ending at (i - 1)
    // and also the max subarray sum starting at (i + 1)
    // and combine them which skips the arr[i] value.

    // Precompute:
    // left[i] = maximum subarray sum ending at i
    // right[i] = maximum subarray sum starting at i

    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        int total = accumulate(arr.begin(), arr.end(), 0);

        vector<int> left(n), right(n);

        // filling left array
        int prev = arr[0], curr = arr[0];
        left[0] = arr[0];

        for(int i = 1; i < n; i++) {
            curr = max(arr[i], prev + arr[i]);
            left[i] = curr;
            prev = curr;
        }

        // filling right array
        prev = arr[n - 1], curr = arr[n - 1];
        right[n - 1] = arr[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            curr = max(arr[i], prev + arr[i]);
            right[i] = curr;
            prev = curr;
        }

        int maxi = INT_MIN;

        for(int i = 1; i < n-1; i++) {
            int temp = left[i - 1] + right[i + 1];
            maxi = max(maxi, temp);
        }

        // we haven't yet tried by deleting the first element or last element
        for(int i = 1; i < n; i++) maxi = max(maxi, right[i]); // try by deleting first element
        for(int i = n - 2; i >= 0; i--) maxi = max(maxi, left[i]); // try by deleting last element

        maxi = max(maxi, total);
        return maxi;
    }
};