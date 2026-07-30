class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();

        string ss = "";
        for(int i = 0; i < n; i++) {
            if(s[i] != '#') ss += s[i];
            else if(ss.size() > 0 && s[i] == '#') ss.pop_back();
        }

        string tt = "";
        for(int i = 0; i < m; i++) {
            if(t[i] != '#') tt += t[i];
            else if(tt.size() > 0 && t[i] == '#') tt.pop_back();
        }

        if(ss == tt) return true;
        return false;
    }
};