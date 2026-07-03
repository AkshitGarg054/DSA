class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> ans;

        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') continue;

            string word = "";
            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            ans.push_back(word);
        }

        string reversed = "";
        for(int i = ans.size() - 1; i >= 0; i--) {
            reversed += ans[i];
            reversed += ' ';
        }

        reversed.pop_back(); // pop the last space
        return reversed;
    }
};