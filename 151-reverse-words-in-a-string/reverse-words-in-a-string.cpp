class Solution {
public:
    // in-place method: O(1) space
    // Clean the string, that is, remove any extra whitespaces in place.
    // reverse the entire string.
    // reverse each word.

    string reverseWords(string s) {
        int n = s.size();
        int i = 0, j = 0;
        
        // clean the string inplace
        while(j < n) {
            while(j < n && s[j] == ' ') j++; // skip extra spaces before word
            while(j < n && s[j] != ' ') s[i++] = s[j++]; // copy word
            while(j < n && s[j] == ' ') j++; // skip extra space after word
            if(j < n) s[i++] = ' '; // add a space after every word
        }

        s.resize(i); // because after cleaning, the string length changed

        // reverse the string s
        reverse(s.begin(), s.end());

        // reverse each word
        int start = 0;
        for(int end = 0; end <= s.size(); end++) {
            if(end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
};