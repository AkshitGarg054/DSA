class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int product = 1, maxi = INT_MIN;

        // left to right pass
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                product = 1;
                continue;
            }
            product *= nums[i];
            maxi = max(maxi, product);
        }

        // right to left pass
        product = 1;
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] == 0) {
                product = 1;
                continue;
            }
            product *= nums[i];
            maxi = max(maxi, product);
        }

        // check zero is present or not.
        bool zero = false;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                zero = true;
                break;
            }
        }

        if(zero == true && maxi < 0) return 0;
        return maxi;
    }
};