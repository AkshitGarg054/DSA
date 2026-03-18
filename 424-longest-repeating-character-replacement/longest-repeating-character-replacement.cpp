class Solution {
public:
    // Expand window with r
    // Track frequency of characters
    // Track maxFreq
    // changes needed in that window : window_size - max_freq
    // If invalid -> shrink from left


    int characterReplacement(string s, int k) {
        int n = s.size();

        unordered_map<char, int> mp;
        int max_freq = 0;
        int l = 0, r = 0;
        int ans = 0;

        while(r < n) {
            mp[s[r]]++;
            max_freq = max(max_freq, mp[s[r]]);

            while((r - l + 1) - max_freq > k) { // more than k changes
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};