class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n != m) return false;

        unordered_map<char, char> st, ts; // s->t , t->s

        for(int i = 0; i < n; i++) {
            if(!st.count(s[i]) && !ts.count(t[i])) {
                st[s[i]] = t[i];
                ts[t[i]] = s[i];
            }
            else if(st[s[i]] != t[i] || ts[t[i]] != s[i]) return false;
        }

        return true;
    }
};