class Solution {
public:
    // For the correct approach, store the indices in the stack to get the length, instead of actual brackets

    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(-1); // base index

        int max_len = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') st.push(i);
            else {
                st.pop();

                if(st.empty()) st.push(i); // reset base
                else max_len = max(max_len, i - st.top());
            }
        }

        return max_len;
    }
};