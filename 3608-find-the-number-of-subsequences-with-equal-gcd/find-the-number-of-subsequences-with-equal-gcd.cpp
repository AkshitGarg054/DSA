class Solution {
public:
    // At every index, there are three choices:
    // put the element in seq1
    // put the element in seq2
    // ignore it
    int dp[201][201][201]; // gcd cannot be greater than the largest value in nums
    const int MOD = 1e9 + 7;

    long long solve(int index, int gcd1, int gcd2, vector<int> &nums) {
        if(index == nums.size()) {
            if(gcd1 != 0 && gcd1 == gcd2) return 1; // we don't want empty subsequences, that is, gcd1 == gcd2 == 0
            return 0;
        }

        if(dp[index][gcd1][gcd2] != -1) return dp[index][gcd1][gcd2];

        long long take1 = solve(index + 1, __gcd(gcd1, nums[index]), gcd2, nums);
        long long take2 = solve(index + 1, gcd1, __gcd(gcd2, nums[index]), nums);
        long long skip = solve(index + 1, gcd1, gcd2, nums);

        return dp[index][gcd1][gcd2] = (take1 + take2 + skip) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        
        memset(dp, -1, sizeof(dp));
        long long ans = solve(0, 0, 0, nums); // index, gcd1, gcd2
        return (int)ans;
    }
};