class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq; // storing indices in deque
        dq.push_back(0); // max score to reach index 0 is numss[0]

        vector<int> dp(n); // dp[i] is the maximum score to reach index i
        dp[0] = nums[0];

        for(int i = 1; i < n; i++) {
            if(dq.front() + k < i) dq.pop_front(); // if the element at front is out of range
            dp[i] = dp[dq.front()] + nums[i]; // maxi is stored at dq.front()

            while(!dq.empty() && dp[dq.back()] < dp[i]) { 
                dq.pop_back(); // remove all smaller elements from back, one by one
            }

            dq.push_back(i); // push the index of dp[i]
        }

        return dp[n-1];
    }
};