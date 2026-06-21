class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        int m = s.size();
        if(m < n) return {};

        vector<int> ans;

        unordered_map<char, int> mp_p;
        for(auto ch: p) mp_p[ch]++;

        unordered_map<char, int> mp_s;
        for(int i = 0; i < n; i++) mp_s[s[i]]++;
        if(mp_p == mp_s) ans.push_back(0);

        int l = 0, r = n;

        while(r < s.size()) {
            mp_s[s[r]]++;

            while((r - l + 1) > n) {
                mp_s[s[l]]--;
                if(mp_s[s[l]] == 0) mp_s.erase(s[l]);
                l++;
            }

            if(r - l + 1 == n && mp_p == mp_s) ans.push_back(l);
            r++; 
        }

        return ans;
    }
};