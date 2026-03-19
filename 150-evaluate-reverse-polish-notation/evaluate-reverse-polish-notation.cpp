class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string> st;
        
        for(int i = 0; i < n; i++) {
            string curr = tokens[i];

            if(curr != "+" && curr != "-" && curr != "*" && curr != "/") {
                st.push(curr);
                continue;
            }

            if(st.size() >= 2) {
                int num2 = stoi(st.top());
                st.pop();
                int num1 = stoi(st.top());
                st.pop();

                int ans;

                if(curr == "+") ans = num1 + num2;
                else if(curr == "-") ans = num1 - num2;
                else if(curr == "*") ans = num1 * num2;
                else if(curr == "/") ans = num1 / num2;

                st.push(to_string(ans));
            }
        }

        return stoi(st.top());
    }
};