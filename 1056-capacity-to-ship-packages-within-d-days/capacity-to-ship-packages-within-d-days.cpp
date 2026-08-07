class Solution {
public:
    bool check(int mid, vector<int> &weights, int d) {
        int days = 0;
        int sum = 0;

        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] > mid) return false;
            if(sum + weights[i] <= mid) sum += weights[i];
            else {
                days++;
                sum = weights[i];
            }
        }

        if(sum > 0) days++;
        return days <= d;
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