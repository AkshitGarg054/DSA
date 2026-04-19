class Solution {
public:
    // in this question, we learned a trick :
    // if we add some string in a string temp --> say, temp = temp + str;
    // and later, we want to remove that string, then how achieve this??? --> we can't simply do : temp = temp - str;
    // to achieve this :
    // we need to store the length of temp before adding str to it, and whenever we want to get the temp back, we can just resize to that len
    // that is, len = temp.size(); --> temp = temp + str --> temp.resize(len);

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