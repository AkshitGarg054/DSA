class Solution {
public:
    bool check(int mid, vector<int> &weights, int days) {
        int required = 0;
        int curr = 0;
        int i = 0;

        while(i < weights.size()) {
            if(weights[i] > mid) return false;
            if(curr + weights[i] <= mid) curr += weights[i];
            else {
                required++;
                curr = weights[i];
            }
            i++;
        }

        if(curr > 0) required++;
        return required <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(check(mid, weights, days)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};