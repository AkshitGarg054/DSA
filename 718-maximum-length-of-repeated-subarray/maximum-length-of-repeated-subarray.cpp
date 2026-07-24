class Solution {
public:
    int dp[1001][1001];

    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if(i >= nums1.size() || j >= nums2.size()) return 0; // if any of the array reaches end, then stop
        if(dp[i][j] != -1) return dp[i][j];

        int take = 0;
        if(nums1[i] == nums2[j]) take = 1 + solve(i + 1, j + 1, nums1, nums2);
        
        return dp[i][j] = take;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = INT_MIN;

        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int temp = solve(i, j, nums1, nums2);
                ans = max(temp, ans);
            }
        }

        return ans;
    }
};