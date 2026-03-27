class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();

        vector<int> prefix_ones(n, 0);
        vector<int> suffix_zeros(n, 0);
        
        prefix_ones[0] = (s[0] == '1');
        suffix_zeros[n-1] = (s[n-1] == '0');

        for(int i = 1; i < n; i++) prefix_ones[i] = prefix_ones[i-1] + (s[i] == '1');
        for(int i = n-2; i >= 0; i--) suffix_zeros[i] = suffix_zeros[i+1] + (s[i] == '0');

         int ans = min(prefix_ones[n - 1], suffix_zeros[0]); // all 0s or all 1s

        for(int i = 0; i < n-1; i++) {
            ans = min(ans, prefix_ones[i] + suffix_zeros[i+1]);
        }

        return ans;
    }
};