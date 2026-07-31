class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        vector<int> prefix(n);
        prefix[0] = (grumpy[0] == 0) ? customers[0] : 0;
        for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + ((grumpy[i] == 0) ? customers[i] : 0);

        int sum = 0;
        for(int i = 0; i < minutes; i++) sum += customers[i];
        int maxi = sum + (prefix[n - 1] - prefix[minutes - 1]);

        int total = prefix[n - 1];
        int l = 0, r = minutes;

        while(r < n) {
            sum += customers[r];

            if(r - l + 1 > minutes) {
                sum -= customers[l];
                l++;
            }

            int temp = sum + (total - (prefix[r] - prefix[l - 1]));
            maxi = max(maxi, temp);
            r++;
        }

        return maxi;
    }
};