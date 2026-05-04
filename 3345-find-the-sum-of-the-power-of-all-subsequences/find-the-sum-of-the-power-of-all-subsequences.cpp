class Solution {
public:
    // If we create a dp[index][sum] then it will become very large, as sum can grow large
    // but, we know that we only want the sum till k, we can write a line: if(sum > k) return 0;
    // so, this will make our dp as dp[n][k]
    // Also, all the elements are positive, so once sum > k, we can't decrease it back to k. (that's why we are able to apply this trick)
    // Now, as the ques states, for each particular subsequence, we want the number of subsequences whose sum == k.
    // So, is it like, we will firstly generate all the subsequences in O(2^n) and then for each, we will apply that O(n * k)??
    // NO
    // Instead, we can simply get to know that a particular subsequence can occur how many times.
    // Let's say, we have nums = {1, 2, 7, 6, 4} , k = 3
    // Then for a subseq [1, 2], it can be a subseq for 2^(3) different subsequences ..that is, 2^(n - count)
    // Now, the issue is with calculating: 2^(n - count) % MOD (n is large, say 100)
    // Whenever we need to calculate this, we always use BINARY EXPONENTIATION.

    int n;
    const int MOD = 1e9 + 7;
    int dp[101][101][101];

    int power(long long a, long long b) {
        if(b == 0) return 1;

        int half = power(a, b / 2);

        int result = (1LL * half * half) % MOD;
        if(b % 2 == 1) result = (1LL * result * a) % MOD;

        return result % MOD;
    }

    int solve(int index, int sum, int count, vector<int> &nums, int k) {
        if(sum > k) return 0;
        if(index == nums.size()) {
            if(sum == k) return power((long long)2, (long long)n - count);
            else return 0;
        }

        if(dp[index][sum][count] != -1) return dp[index][sum][count];

        int take = solve(index + 1, sum + nums[index], count + 1, nums, k);
        int skip = solve(index + 1, sum, count, nums, k);

        return dp[index][sum][count] = (take + skip) % MOD;
    }

    int sumOfPower(vector<int>& nums, int k) {
        n = nums.size();

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums, k); // index, sum, count
    }
};