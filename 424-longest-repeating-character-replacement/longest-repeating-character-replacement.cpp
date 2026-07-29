class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int l = 0, r = 0;
        int max_freq = INT_MIN;
        unordered_map<char, int> mp;
        int ans = INT_MIN;

        while(r < n) {
            mp[s[r]]++;
            max_freq = max(max_freq, mp[s[r]]);

            while((r - l + 1) - max_freq > k) {
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};