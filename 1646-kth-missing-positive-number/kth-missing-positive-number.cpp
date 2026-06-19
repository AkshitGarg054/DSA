class Solution {
public:
    // approach 3: binary search
    // In a sorted array, at index i, the number of missing positives before arr[i] is: arr[i] - (i + 1)
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] - (mid + 1) >= k) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        if(ans == 0) return k;
        if(ans == -1) return n + k;

        int prev = ans - 1;
        int prev_missing = arr[prev] - (prev + 1);
        return arr[prev] + (k - prev_missing);
    }
};