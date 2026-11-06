class Solution {
public:
    // If a number repeats, we are stuck in an infinite cycle. So, we use a set to track previously visited numbers.

    int getSum(int n) {
        int sum = 0;

        while(n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> st;

        while(n != 1 && st.find(n) == st.end()) {
            st.insert(n);
            n = getSum(n);
        }

        return n == 1;
    }
};