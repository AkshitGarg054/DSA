class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<int> isPrime(n, 1);

        for(int i = 2; i < n; i++) {
            if(isPrime[i]) {
                count++;
                for(int j = 2*i; j < n; j += i) isPrime[j] = 0;
            }
        }

        return count;
    }
};