class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        int product = 1;

        // left to right pass
        for(int i = 0; i < n; i++) {
            product *= nums[i];
            maxi = max(maxi, product);
            if(product == 0) product = 1;
        }

        product = 1;

        // right to left pass
        for(int i = n - 1; i >= 0; i--) {
            product *= nums[i];
            maxi = max(maxi, product);
            if(product == 0) product = 1;
        }

        return maxi;
    }
};