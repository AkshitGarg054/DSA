class Solution {
public:
    // maximum product hi to nikalna haii, so isme to bss normally left se right traverse krenge
    // product krte jayenge aur maximum store krte jayenge
    // but problem will arise when beech me zero aa jaye.
    // hm left se right jaa rhe hn aur beech me ek bar bhi zero se multiply ho gyaa, to aage ke sabhi elements ka prodyct zero hi ayega
    // aur fir hm aage ke elements ke liye max product store ni kr payenge
    // so what we do is ki ..product me element ko add krne se pehle, we need to check ki whether it is zero or not
    // if zero haii to hm usko product me add ni krenge, and product = 1 se start krenge, aage wale elements ke liye. (to consider both left and right side)
    // There is one more issue : {3, -1, 4} --> this shows that backward pass is also needed

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