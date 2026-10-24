class Solution {
public:
    vector<string> strs = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;

    void solve(int index, string &temp, string &digits) {
        if(index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        int digit = digits[index] - '0';

        for(auto &ch: strs[digit]) {
            temp += ch;
            solve(index + 1, temp, digits);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();

        string temp = "";
        solve(0, temp, digits);
        return ans;
    }
};