class Solution {
public:
    int reverse_num(int x) {
        int rev = 0;    
        while(x > 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x = x / 10;
        }
        return rev;
    }

    int mirrorDistance(int n) {
        return abs(n - reverse_num(n));
    }
};