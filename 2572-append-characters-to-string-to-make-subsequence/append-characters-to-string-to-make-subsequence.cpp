class Solution {
public:
    // always remember that : to check whether a string y is present in string x as a subsequence or not, we follow this template

    int appendCharacters(string s, string t) {
        int i = 0, j = 0;

        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) j++;
            i++;
        }

        return t.size() - j;
    }
};