class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        int ans = 0;

        // binary search for the largest mid such that mid*mid <= x
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if((long long)mid * mid <= x) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }

        return ans;
    }
};