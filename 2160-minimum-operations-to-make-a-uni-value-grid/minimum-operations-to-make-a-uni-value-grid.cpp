class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        for(auto i : grid) {
            for(auto j : i) {
                nums.push_back(j);
            }
        }

        sort(nums.begin(), nums.end());
        int mid = nums[nums.size() / 2];
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            int diff = abs(nums[i] - mid);
            if(diff % x != 0) return -1;
            ans += (diff / x);
        }

        return ans;
    }
};