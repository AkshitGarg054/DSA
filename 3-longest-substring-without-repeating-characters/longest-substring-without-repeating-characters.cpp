class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;

        unordered_map<char, int> mp;
        int l = 0, r = 0;
        int ans = INT_MIN;

        while(r < n) {
            mp[s[r]]++;

            while(mp[s[r]] > 1) {
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