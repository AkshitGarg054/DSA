class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        int i = n - 1;

        while(i >= 0) {
            if(s[i] == ' ') {
                i--;
                continue;
            }

            int j = i;
            while(j >= 0 && s[j] != ' ') j--;
            ans += s.substr(j + 1, i - j);
            ans += ' ';

            i = j - 1;
        }

        ans.pop_back(); // remove last whitespace 
        return ans; 
    }
};