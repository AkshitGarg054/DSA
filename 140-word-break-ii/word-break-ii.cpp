class Solution {
public:
    int n;
    vector<string> ans;
    unordered_set<string> st;

    void solve(int index, string &temp, string &s) {
        if(index == n) {
            temp.pop_back(); // remove last space
            ans.push_back(temp);
            temp.push_back(' '); // restore for backtracking
            return;
        }

        for(int i = index; i < n; i++) {
            string str = s.substr(index, i - index + 1);

            if(st.count(str)) {
                int len = temp.size(); // store old length, so that we can later resize back to this length

                temp += str + ' ';
                solve(i + 1, temp, s);
                temp.resize(len); // backtrack --> resize back to len
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(auto word : wordDict) st.insert(word);
        
        string temp = "";
        solve(0, temp, s);
        return ans;
    }
};