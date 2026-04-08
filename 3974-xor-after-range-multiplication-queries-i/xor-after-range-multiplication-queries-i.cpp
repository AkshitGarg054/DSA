class Solution {
public:
    const int MOD = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        for(auto query : queries) {
            int l = query[0], r = query[1];
            int k = query[2], v = query[3];

            for(int i = l; i <= r; i = i + k) {
                nums[i] = (1LL * nums[i] * v) % MOD;
            }
        }

        int xorr = 0;
        for(int i = 0; i < n; i++) xorr = xorr ^ nums[i];

        return xorr;
    }
};