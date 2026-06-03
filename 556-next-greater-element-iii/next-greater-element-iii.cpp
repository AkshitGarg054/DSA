class Solution {
public:
    // It's just the "Next Permutation"

    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        long long ans = stoll(s);

        if(n >= ans) return -1; // like, n = 21, ans = 12
        if(ans > INT_MAX) return -1;
        return ans;
    }
};