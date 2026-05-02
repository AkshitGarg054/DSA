class Solution {
public:
    // A subarray has odd sum -> when the prefix sum at its ends have different parity (one even, one odd)
    // try to think ki prefix[r] - prefix[l-1] = odd kb kb hoga
    // because it gives the sum of a subarray.
    // even - odd = odd 
    // odd - even = odd
    // if prefix[r] is even, then it will make odd sum subarray with all prefix[i < r] that are odd
    // similarly, if prefix[r] is odd, then it will make odd sum subarray with all prefix[i < r] that are even

    const int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int odd = 0, even = 1; // empty prefix is even
        int count = 0, sum = 0;

        for(int i = 0; i < n; i++) {
            sum += arr[i];

            if(sum % 2 == 0) { // prefix[r] is even
                count = (count + odd) % MOD;
                even++;
            }
            else { // prefix[r] is odd
                count = (count + even) % MOD;
                odd++;
            }
        }

        return count;
    }
};