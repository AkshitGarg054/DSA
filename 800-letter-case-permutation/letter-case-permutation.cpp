class Solution {
public:
    // isalpha(ch) --> to check whether char is a english alphabet or not
    // isdigit(ch) --> to check if char is a digit or not
    // toupper(ch) --> to convert lowercase char to uppercase
    // say, ch = 'a' --> char upper = ch - 'a' + 'A' (another method to convert into uppercase)
    vector<string> ans;

    void solve(int index, string temp, string &s) {
        if(index == s.size()) {
            ans.push_back(temp);
            return;
        }

        if(isalpha(s[index]) && s[index] >= 'a' && s[index] <= 'z') {
            solve(index + 1, temp + s[index], s);
            solve(index + 1, temp + (char)toupper(s[index]), s);
        } 
        else if(isalpha(s[index]) && s[index] >= 'A' && s[index] <= 'Z') {
            solve(index + 1, temp + s[index], s);
            solve(index + 1, temp + (char)tolower(s[index]), s);
        }
        else solve(index + 1, temp + s[index], s);
    }

    vector<string> letterCasePermutation(string s) {
        solve(0, "", s);
        return ans;
    }
};