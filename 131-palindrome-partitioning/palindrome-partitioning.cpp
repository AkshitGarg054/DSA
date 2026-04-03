class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string &s) {
        int l = 0, r = s.size() - 1;

        while(l < r) {
            if(s[l] != s[r]) return false;
            l++, r--;
        }

        return true;
    }

    void solve(string s, vector<string> &temp) {
        if(s.size() == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i+1);
            if(isPalindrome(part)) {
                temp.push_back(part);
                solve(s.substr(i + 1), temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> temp;
        solve(s, temp);
        return ans;
    }
};