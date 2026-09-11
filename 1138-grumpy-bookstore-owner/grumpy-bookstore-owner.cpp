class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int k = minutes;

        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) arr[i] = 0;
            else arr[i] = customers[i];
        }

        // find the subarray of size 'minutes' with max sum in the grumpy array
        int sum = 0;
        for(int i = 0; i < k; i++) sum += arr[i];
        int maxi = sum;
        int start = 0;

        int l = 0, r = 0;

        while(r < n) {
            sum += arr[r];

            if(r - l + 1 > k) {
                sum -= arr[l];
                l++;
            }

            if(sum > maxi) {
                maxi = sum;
                start = l;
            }
            r++;
        }

        int ans = 0;
        for(int i = start; i < start + k; i++) ans += customers[i]; // all customers are satisfied
        for(int i = 0; i < start; i++) if(grumpy[i] == 0) ans += customers[i];
        for(int i = start + k; i < n; i++) if(grumpy[i] == 0) ans += customers[i];

        return ans;
    }
};