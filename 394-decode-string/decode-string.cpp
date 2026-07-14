class Solution {
public:
    // to convert a char to a string, we do: string(1, ch) ...not to_string(ch)

    string decodeString(string s) {
        int n = s.size();
        stack<string> st; // as the digits range from 1 to 300
        int num = 0;

        // input: 3[a2[bc]]
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if(s[i] >= '0' && s[i] <= '9') num = num*10 + (ch - '0'); 
            else if(s[i] == '[') {
                st.push(to_string(num));
                num = 0;
            }
            else if(s[i] >= 'a' && s[i] <= 'z') st.push(string(1, ch));
            else if(s[i] == ']') {
                string temp = "";
                // pop till we find a number
                while(!st.empty() && (st.top()[0] >= 'a' && st.top()[0] <= 'z')) {
                    temp += st.top();
                    st.pop();
                }

                // temp = "cb"
                reverse(temp.begin(), temp.end()); // bc
                int freq = stoi(st.top());
                st.pop();

                string duplicated = "";
                for(int i = 0; i < freq; i++) duplicated += temp; // duplicated = "bcbc"
                for(int i = 0; i < duplicated.size(); i++) st.push(string(1, duplicated[i]));
            }
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};