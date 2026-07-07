class Solution {
public:
    double solve(double x, long long n) {
        if(n == 0) return 1;
        if(n == 1) return x;

        double half = solve(x, n / 2);
        if(n % 2 == 0) return half * half;
        return half * half * x;
    }

    double myPow(double x, int n) {
        long long N = n;
        if(N < 0) {
            x = 1 / x;
            N = -N; // if n is INT_MIN, then -n will get overflow, so we need n to be long long
        }

        return solve(x, N);
    }
};