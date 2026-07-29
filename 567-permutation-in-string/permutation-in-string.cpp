class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(m < n) return false;

        unordered_map<char, int> mp1; 
        for(auto &ch: s1) mp1[ch]++;

        unordered_map<char, int> mp2;
        for(int i = 0; i < n; i++) mp2[s2[i]]++;
        if(mp1 == mp2) return true; // checking the first window

        int l = 0, r = n; // fixed size sliding window
        
        while(r < m) {
            mp2[s2[r]]++;

            while(r - l + 1 > n) {
                mp2[s2[l]]--;
                if(mp2[s2[l]] == 0) mp2.erase(s2[l]);
                l++;
            }

            if(r - l + 1 == n && mp1 == mp2) return true;
            r++;
        }

        return false;
    }
};