class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";

        auto expand_from_center = [&](int l, int r) {
            while(l >= 0 && r < s.size()) {
                if(s[l] != s[r]) return s.substr(l + 1, r - l - 1);
                l--, r++;
            }
            return s.substr(l + 1, r - l - 1);
        };

        for(int i = 0; i < n; i++) {
            string odd = expand_from_center(i, i);
            string even = expand_from_center(i, i + 1);
            
            if(odd.size() > ans.size()) ans = odd;
            if(even.size() > ans.size()) ans = even;
        }

        return ans;
    }
};