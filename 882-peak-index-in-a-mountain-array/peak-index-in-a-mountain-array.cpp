class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        int low = 0, high = n-1;
        int ans = -1;

        while(low < high) { // don't put equality, coz we stop at low == high
            int mid = low + (high - low) / 2;

            // keep narrowing the search space and always keep the peak inside [low, high]
            // so, at the end, we will stop at low == high and that will point to peak
            if(arr[mid] < arr[mid + 1]) low = mid + 1;
            else high = mid;
        }

        return low; // or high
    }
};