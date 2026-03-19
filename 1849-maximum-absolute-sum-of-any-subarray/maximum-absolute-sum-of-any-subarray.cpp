class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int ans1 = INT_MIN, sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            ans1 = max(ans1, sum);
            if(sum < 0) sum = 0;
        }

        int ans2 = INT_MIN;
        sum = 0;

        for(int i = 0; i < n; i++) nums[i] = -nums[i];

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            ans2 = max(ans2, sum);
            if(sum < 0) sum = 0;
        }

        return max(ans1, ans2);
    }
};