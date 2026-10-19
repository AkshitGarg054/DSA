class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2) {
        if(i == n || j == m) return INT_MIN; // to ensure that the subseq is non-empty. If we return 0, then a -ve valid answer will not be able to consider and 0 will be returned. (Third test case)
        if(dp[i][j] != -1) return dp[i][j];

        long long take = nums1[i] * nums2[j];
        take = max(take, take + solve(i + 1, j + 1, nums1, nums2));

        long long skip1 = solve(i, j + 1, nums1, nums2);
        long long skip2 = solve(i + 1, j, nums1, nums2);

        return dp[i][j] = (int)max({take, skip1, skip2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        dp.resize(n, vector<int>(m, -1));

        return solve(0, 0, nums1, nums2);
    }
};