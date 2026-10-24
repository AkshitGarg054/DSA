class Solution {
public:
    const int MOD = 1e9 + 7;

    long long calc(long long x, long long n) { // x^n
        if(n == 0) return 1;
        if(n == 1) return x;

        long long half = calc(x, n / 2);  
        long long ans = half * half % MOD; 

        if(n & 1) ans = (ans * x) % MOD;
        return ans; 
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; // number of even positions (0, 2, 4, 6, 8)
        long long odd = n / 2; // (2, 3, 5, 7)

        int ans = (calc(5, even) % MOD * calc(4, odd)) % MOD;
        return ans;
    }
};