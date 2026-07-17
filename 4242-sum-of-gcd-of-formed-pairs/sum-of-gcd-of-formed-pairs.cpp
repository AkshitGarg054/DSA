class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n);
        prefix[0] = nums[0];
        int maxi = nums[0];

        for(int i = 1; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefix[i] = __gcd(maxi, nums[i]);
        }

        sort(prefix.begin(), prefix.end());

        long long sum = 0;
        int i = 0, j = n - 1;

        while(i < j) {
            int ele1 = prefix[i++];
            int ele2 = prefix[j--];
            sum += __gcd(ele1, ele2);
        }

        return sum;
    }
};