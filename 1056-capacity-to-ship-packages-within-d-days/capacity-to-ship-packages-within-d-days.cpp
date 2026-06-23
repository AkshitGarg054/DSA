class Solution {
public:
    bool check(vector<int> &weights, int capacity, int days) {
        int required = 0; // required days
        int sum = 0;

        for(int i = 0; i < weights.size(); i++) {
            if(sum + weights[i] <= capacity) sum += weights[i];
            else {
                required++;
                sum = weights[i];
            }
        }

        required++; // for last shipping
        return required <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end()); 
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(check(weights, mid, days)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};