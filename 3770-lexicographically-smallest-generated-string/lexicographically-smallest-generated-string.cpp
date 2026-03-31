class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        string ans(n + m - 1, 'a');
        vector<bool> locked(n + m - 1, false);

        // firstly, force all T conditions and lock the positions
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                for(int j = i; j < i + m; j++) {
                    if(locked[j] == true && ans[j] != str2[j - i]) return "";
                    ans[j] = str2[j - i];
                    locked[j] = true;
                }
            }
        }

        // check F conditions
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'F') {
                bool match = true;
                for(int j = i; j < i + m; j++) {
                    if(ans[j] != str2[j - i]) {
                        match = false;
                        break;
                    }
                }

                if(match == true) {
                    bool broken = false; // try to break the match
                    for(int j = i + m - 1; j >= i; j--) { // started from back, to ensure lexicographically smallest
                        if(!locked[j]) { // if j is not locked, then try changing it
                            ans[j] = (str2[j-i] == 'a' ? 'b' : 'a'); // to ensure lexicographically smallest
                            broken = true;
                            break;
                        }
                    }

                    if(!broken) return "";
                }
            }
        }

        return ans;
    }
};