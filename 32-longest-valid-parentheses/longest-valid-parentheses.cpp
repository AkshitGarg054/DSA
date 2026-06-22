class Solution {
public:
    // To write a correct approach, knowing the chars isn't enough
    // we need to know exactly where they are. (that is, their position)
    // so, instead of pushing chars, we will push indices
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int ans = 0;

        st.push(-1); // initial base boundary

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') st.push(i);
            else {
                st.pop(); // it can be either '(' or a previous boundary

                if(st.empty()) { // it means, that was a previous boundary
                    st.push(i); // This ')' is invalid and forms a new base boundary
                }
                else {
                    int len = i - st.top();
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};