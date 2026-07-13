class Solution {
public:
    // let's say we choose a fixed number k.
    // Define: b[i] = nums[i] if divisible by k, or -nums[i] if not.
    // Now, alice wants to choose [l, r] to maximize summation(b[i]) over l to r.
    // which is simply maximum subarray sum (kadane)
    // So, for a fixed k, it's easy. Build b[i] and run kadane.
    // But which values of k we need to try?
    // The chosen k should be divisible by atleast one element of nums.
    // so we can try for all divisors of numbers in nums.
    const int MOD = 1e9 + 7;

    int kadane(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> vec(n);

        for(int i = 0; i < n; i++) {
            if(nums[i] % k == 0) vec[i] = nums[i];
            else vec[i] = -nums[i];
        }

        // apply kadane (we want maximum subarray sum even when it is negative, so don't allow the empty subarray, that is, maxi = 0) 
        int sum = 0;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            sum += vec[i];
            maxi = max(maxi, sum);
            if(sum < 0) sum = 0;
        }

        return maxi;
    }

    int divisibleGame(vector<int>& nums) {
        int n = nums.size();
        // we need to check for k = 2, 3, 4, 5, 6, 7....
        // Incase of even numbers, 2, 4, 6, 8.... if a num is divisible by 4 then it is also divisible by 2.
        // So, we can only check for k = 2, and all odd numbers.
        // But still this gives TLE.
        // We need to try all the divisors only.

        unordered_set<int> divisors;

        // extract all divisors > 1
        for(int x: nums) {
            for(int d = 2; d*d <= x; d++) {
                if(x % d == 0) {
                    divisors.insert(d);
                    divisors.insert(x / d);
                }
            }

            if(x > 1) divisors.insert(x);
        }

        int best_sum = kadane(nums, 2); // k = 2 should always be considered, for edge cases like: nums = [1] 
        int best_k = 2;

        for(int k: divisors) {
            int sum = kadane(nums, k);

            if(sum > best_sum) {
                best_sum = sum;
                best_k = k;
            }
            else if(sum == best_sum && k < best_k) best_k = k;
        }

        cout << best_sum << " " << best_k << endl;
        return ((1LL * best_sum * best_k) % MOD + MOD) % MOD;
    }
};