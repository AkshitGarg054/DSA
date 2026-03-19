class Solution {
public:
    // in normal kadane question, we find the normal maximum subarray sum
    // but here, absolute sum ka maximum nikalna haiii
    // mtlb maximum negative sum jo ayega, vo bhi hm consider kr skte hn, uska absolute leke.
    // isliye, i thought of ki, saare elements ka sign change kr deta hu, to maximum negative sum will become positive
    // and fir last me, normal max sum, and negative max sum wale ko compare krke, max return kr dunga

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