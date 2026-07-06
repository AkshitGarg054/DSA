class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        int i = 0;
        while(i < n) {
            string curr = tokens[i];

            if(curr != "+" && curr != "-" && curr != "*" && curr != "/") st.push(stoi(curr));
            else {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();

                if(curr == "+") st.push(num1 + num2);
                else if(curr == "-") st.push(num1 - num2);
                else if(curr == "/") st.push(num1 / num2);
                else if(curr == "*") st.push(num1 * num2);
            }

            i++;
        }

        return st.top();
    }
};