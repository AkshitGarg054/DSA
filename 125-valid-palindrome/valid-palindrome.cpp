class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string str = "";

        for(int i = 0; i < n; i++) {
            if(s[i] >= 'a' && s[i] <= 'z') str += s[i];
            else if(s[i] >= 'A' && s[i] <= 'Z') str += tolower(s[i]);
            else if(s[i] >= '0' && s[i] <= '9') str += s[i];
        }

        string original = str;
        reverse(str.begin(), str.end());
        if(str == original) return true;
        return false;
    }
};