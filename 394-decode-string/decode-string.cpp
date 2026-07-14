class Solution {
public:
    // We need to pass the index by reference as we want all the recursive calls to share the same index.

    string solve(int &index, string &s) {
        string temp = "";

        while(index < s.size() && s[index] != ']') {

            if(isdigit(s[index])) {
                int freq = 0;
                while(isdigit(s[index])) {
                    freq = freq * 10 + (s[index] - '0');
                    index++;
                }

                index++; // skip '['
                string curr = solve(index, s);
                index++; // skip ']'
                while(freq--) temp += curr;
            }
            else if(s[index] >= 'a' && s[index] <= 'z') {
                while(s[index] >= 'a' && s[index] <= 'z') temp += s[index++];
            }
        }

        return temp;
    }

    string decodeString(string s) {
        int n = s.size();
        int index = 0;
        string ans = solve(index, s);
        return ans;
    }
};