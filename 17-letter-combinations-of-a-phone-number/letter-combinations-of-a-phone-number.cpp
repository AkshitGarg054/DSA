class Solution {
public:
    vector<string> KEYS = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;

    void solve(int index, string temp, string &digits) {
        if(index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        int digit = digits[index] - '0';

        for(char ch : KEYS[digit]) {
            solve(index + 1, temp + ch, digits);
        }
    }

    vector<string> letterCombinations(string digits) {
        solve(0, "", digits);
        return ans;
    }
};