class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(s[i] == '*') st.pop();
            else st.push(s[i]);
        }

        string str = "";
        while(!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }

        reverse(str.begin(), str.end());
        return str;
    }
};