class Solution {
public:
    // Partition the stones into two groups such that their weight difference is minimum
    // then we can just smash the two groups, and their difference will be left out.
    // similar to 0/1 knapsack or subset sum
    // total_sum = sum --> try to find subset with sum ~ sum / 2
    // target = sum / 2
    // find maximum subset sum <= target

    int dp[31][3001];

    int solve(int index, int sum, int target, vector<int> &nums) {
        if(index == nums.size()) return sum;
        if(dp[index][sum] != -1) return dp[index][sum];

        int take = INT_MIN;
        if(sum + nums[index] <= target) take = solve(index + 1, sum + nums[index], target, nums);

        // not take
        int skip = solve(index + 1, sum, target, nums);

        return dp[index][sum] = max(take, skip);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int total_sum = 0;
        for(int x : stones) total_sum += x;

        memset(dp, -1, sizeof(dp));

        int target = total_sum / 2;
        int subset_sum = solve(0, 0, target, stones);

        int s1 = subset_sum;
        int s2 = total_sum - subset_sum;
        return abs(s1 - s2);
    }
};