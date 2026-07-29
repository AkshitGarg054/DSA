class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();

        vector<string> arr;
        string temp = "";
        int i = 0;

        while(i < s.size()) {
            char ch = s[i];

            if(ch >= 'a' && ch <= 'z') temp += ch;
            else if(ch == ' ') {
                arr.push_back(temp);
                temp.clear();
            }
            i++;
        }

        arr.push_back(temp); // push last word

        unordered_map<char, string> ps; // p -> s
        unordered_map<string, char> sp; // s -> p

        if(n != arr.size()) return false;

        for(int i = 0; i < n; i++) {
            char ch = pattern[i];
            string str = arr[i];

            if(!ps.count(ch) && !sp.count(str)) {
                ps[ch] = str;
                sp[str] = ch;
            }
            else if(ps[ch] != str || sp[str] != ch) return false;
        }

        return true;
    }
};