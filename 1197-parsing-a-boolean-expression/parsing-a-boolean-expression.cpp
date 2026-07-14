class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<char> st;

        for(int i = 0; i < n; i++) {
            char ch = expression[i];

            if(ch == '(' || ch == ',') continue;
            else if(ch != ')') st.push(ch);
            else if(ch == ')') {
                int t = 0;
                int f = 0;

                while(st.top() == 't' || st.top() == 'f') {
                    char c = st.top();
                    st.pop();
                    if(c == 't') t++;
                    else f++;
                }

                char op = st.top();
                st.pop();

                if(op == '|') {
                    if(t > 0) st.push('t');
                    else st.push('f');
                }
                else if(op == '&') {
                    if(f > 0) st.push('f');
                    else st.push('t');
                }
                else if(op == '!') {
                    if(t == 1) st.push('f');
                    else if(f == 1) st.push('t');
                }
            }
        }

        if(st.top() == 't') return true;
        return false;
    }
};