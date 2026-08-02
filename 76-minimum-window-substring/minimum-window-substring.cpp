class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char, int> mpt, mps;
        for(auto &ch: t) mpt[ch]++;

        int l = 0, r = 0;
        int found = 0;
        int mini = INT_MAX;
        int start = -1;

        while(r < n) {
            char ch = s[r];

            mps[ch]++;
            if(mpt.count(ch) && mps[ch] <= mpt[ch]) found++;

            while(found == t.size()) {
                if(r - l + 1 < mini) {
                    mini = r - l + 1;
                    start = l;
                }

                mps[s[l]]--;
                if(mpt.count(s[l]) && mps[s[l]] < mpt[s[l]]) found--;
                if(mps[s[l]] == 0) mps.erase(s[l]);
                l++;
            }

            r++;
        }

        if(start == -1) return "";
        return s.substr(start, mini);
    }
};