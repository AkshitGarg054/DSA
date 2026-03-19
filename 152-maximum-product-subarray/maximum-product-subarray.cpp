class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int product = 1, ans = INT_MIN;

        // forward pass
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                product = 1;
                continue;
            }

            product *= nums[i];
            ans = max(ans, product);
        }

        // backward pass
        product = 1;

        for(int i = n-1; i >= 0; i--) {
            if(nums[i] == 0) {
                product = 1;
                continue;
            }

            product *= nums[i];
            ans = max(ans, product);
        }

        bool zero = false;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                zero = true;
                break;
            }
        }

        if(zero == true && ans < 0) return 0; // for nums = {-1, 0, -2}
        return ans;
    }
};