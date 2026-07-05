class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int mini = INT_MAX;
        int jumps = 0;

        int i = 0;
        while(i < n) {
            int limit = i + nums[i];
            if(limit >= n - 1) return jumps + 1;
            int maxi = INT_MIN;

            int j = i + 1;
            int index = -1;
            while(j <= limit) {
                int new_limit = j + nums[j];
                if(new_limit >= maxi) {
                    maxi = new_limit;
                    index = j;
                }
                j++;
            }

            jumps++;
            if(maxi >= n - 1) return jumps + 1; // 1 added for last jump
            i = index;
        }

        return jumps + 1;
    }
};