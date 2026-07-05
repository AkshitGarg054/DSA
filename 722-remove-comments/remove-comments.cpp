class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        int n = source.size();
        vector<string> ans;
        bool start = false;
        string temp = "";

        for(auto &s: source) {
            if(start == true && s.find("*/") == string::npos) continue;
        
            int i = 0;
            while(i < s.size()) {
                if(start == false) {
                    if(i + 1 < s.size() && s[i] == '/' && s[i + 1] == '/') break;
                    else if(i + 1 < s.size() && s[i] == '/' && s[i + 1] == '*') {
                        start = true;
                        i = i + 2;
                    }
                    else temp += s[i++];
                }
                else {
                    if(i + 1 < s.size() && s[i] == '*' && s[i + 1] == '/') {
                        start = false; 
                        i = i + 2;
                    }
                    else i++;
                }
            }

            if(start == false && !temp.empty()) {
                ans.push_back(temp);
                temp.clear();
            }
        }

        return ans;
    }
};