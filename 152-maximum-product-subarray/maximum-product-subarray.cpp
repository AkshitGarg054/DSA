class Solution {
public:
    // this approach is very similar to kadane.

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int product = 1, maxi = INT_MIN;

        // left to right pass
        for(int i = 0; i < n; i++) {
            product *= nums[i];
            maxi = max(maxi, product);
            if(product == 0) product = 1;
        }

        // right to left pass
        product = 1;
        for(int i = n - 1; i >= 0; i--) {
            product *= nums[i];
            maxi = max(maxi, product);
            if(product == 0) product = 1; 
        }

        return maxi;
    }
};