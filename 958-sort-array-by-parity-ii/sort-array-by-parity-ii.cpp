class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd, even;

        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 != 0) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }

        int i = 0, j = 0;
        for(int k = 0; k < n; k++) {
            if(k % 2 == 0) nums[k] = even[i++];
            else nums[k] = odd[j++];
        }

        return nums;
    }
};