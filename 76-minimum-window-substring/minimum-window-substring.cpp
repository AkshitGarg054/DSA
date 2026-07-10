class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char, int> mp;
        for(auto &ch: t) mp[ch]++;

        int l = 0, r = 0;
        int mini = 1e8;
        int count = 0;
        int start = -1;

        while(r < n) {
            char curr = s[r];

            if(mp.count(curr)) {
                if(mp[curr] > 0) count++;
                mp[curr]--; // keep decremting to store the extra chars also
            }

            while(count == m) {
                if(r - l + 1 < mini) {
                    mini = r - l + 1;
                    start = l;
                }

                // shrink window
                char remove = s[l];

                if(!mp.count(remove)) l++;
                else {
                    mp[remove]++; 
                    if(mp[remove] > 0) count--;
                    l++;
                }
            }

            r++;
        }

        if(start == -1) return "";
        return s.substr(start, mini);
    }
};