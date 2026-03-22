class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        int curr_far = 0 + nums[0]; // we will firstly traverse this window completely and select the farthest from that
        // and will increment the count only once for each window
        int farthest = curr_far;
        int count = 0;

        if(curr_far >= n-1) return 1; // {2, 1}

        int i = 0;
        while(i <= curr_far && i < n) {
            farthest = max(farthest, i + nums[i]); // choose the farthest from the current window
            
            if(i == curr_far) { // when current window gets over
                curr_far = farthest; // then set the new window to the new farthest
                count++; // and we did one jump in one window 
                if(curr_far >= n-1) return count + 1; // one jump extra for last jump
            }
            
            i++;
        }

        return count;
    }
};