class Solution {
public:
    int lessThanK(int el, int m, int n) {
        int count = 0;
        for(int i = 1; i <= m; i++) {
            count += min(el / i, n);
        }

        return count;
    }

    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int count = lessThanK(mid, m, n);
            if(count >= k) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};