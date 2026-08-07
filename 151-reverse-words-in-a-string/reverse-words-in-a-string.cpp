class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> words;

        int i = 0;
        string temp = "";

        while(i < n) {
            if(isalnum(s[i])) temp += s[i];
            else if(s[i] == ' ') {
                if(!temp.empty()) words.push_back(temp);
                temp.clear();
            }
            i++;
        }

        if(!temp.empty()) words.push_back(temp);

        string ans = "";

        for(int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];
            ans += ' ';
        }

        ans.pop_back();
        return ans;
    }
};