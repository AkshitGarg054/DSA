class Solution {
public:
    // As longest repeating char ki baat ho rhi haii, so we can use a map
    int characterReplacement(string s, int k) {
        int n = s.size();

        unordered_map<char, int> mp;
        int l = 0, r = 0;
        int max_freq = INT_MIN;
        int ans = INT_MIN;

        while(r < n) {
            mp[s[r]]++;
            max_freq = max(max_freq, mp[s[r]]);

            while((r - l + 1) - max_freq > k) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};