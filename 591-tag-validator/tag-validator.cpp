class Solution {
public:
    // the order of checking should be: <![CDATA[ --> </ --> <.
    // Because if we check '<' first, then '<' is contained in cdata and closing tag too, so we don't know whether we should look for open tag, closed tag or cdata
    // Also note: find() returns string::npos when not found.

    bool check(string &s) { // to check validity of tagName
        // s should contain only uppercase letters and has length in range [1, 9]
        if(s.size() < 1 || s.size() > 9) return false;
        for(char ch: s) {
            if(ch < 'A' || ch > 'Z') return false;
        }
        return true;
    }

    bool isValid(string code) {
        int n = code.size();   
        if(code.empty() || code[0] != '<') return false;

        stack<string> st;
        int i = 0;

        while(i < n) {
            if(i > 0 && st.empty()) return false; // if stack becomes empty before the end of string then return false

            if(code.substr(i, 9) == "<![CDATA[") {
                if(st.empty()) return false; // cdata must be inside a tag

                // search for "]]>" 
                int j = code.find("]]>", i + 9);
                if(j == string::npos) return false;
                else i = j + 3;
            }
            else if(code.substr(i, 2) == "</") { // end tag
                if(st.empty()) return false; 
                int j = code.find(">", i + 2);
                if(j == string::npos) return false;

                string tagName = code.substr(i + 2, j - (i + 2));
                if(!check(tagName)) return false;

                if(st.top() != tagName) return false; // we don't want <A></B> to get accepted
                st.pop(); // if valid, pop the open tag for this closed tag
                i = j + 1;
            }
            else if(code[i] == '<') { // opening tag
                int j = code.find(">", i + 1); // s.find() finds the just closest '>' from multiple occurences
                if(j == string::npos) return false;

                string tagName = code.substr(i + 1, j - (i + 1));
                if(!check(tagName)) return false;

                st.push(tagName); // if valid, push into stack
                i = j + 1; 
            }
            else { // regular characters
                if(st.empty()) return false; // characters must be inside a tag
                i++;
            }
        }

        if(!st.empty()) return false; 
        return true;
    }
};