class Solution {
public:
    vector<vector<int>> dp;

    int solve(int index, int prev, vector<int> &arr) {
        if(index == arr.size()) return 0;
        if(prev != -1 && dp[index][prev] != -1) return dp[index][prev];

        int take = 0, skip = 0;
        if(arr[index] != 0 && (prev == -1 || (prev == 0 && arr[index] > 0) || (prev == 1 && arr[index] < 0))) {
            int curr = (arr[index] > 0) ? 1 : 0;
            take = 1 + solve(index + 1, curr, arr);
        }
        skip = solve(index + 1, prev, arr);

        if(prev == -1) return max(take, skip);
        return dp[index][prev] = max(take, skip);
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2 && nums[1] - nums[0] == 0) return 1;
        if(n == 2) return 2;

        vector<int> seq;
        for(int i = 1; i < n; i++) seq.push_back(nums[i] - nums[i - 1]);

        dp.assign(n, vector<int>(3, -1));
        int ans = solve(0, -1, seq); // prev = 1 for +ve and 0 for -ve
        return ans + 1; // +1 because we have find the longest sequence in seq array.
    }
};