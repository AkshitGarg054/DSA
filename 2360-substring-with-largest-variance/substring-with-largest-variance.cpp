class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        int ans = 0;

        vector<int> count(26, '0');
        for(auto ch: s) count[ch - 'a']++;

        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                if(i == j || count[i] == 0 || count[j] == 0) continue;

                char major = 'a' + i;
                char minor = 'a' + j;
                int major_count = 0, minor_count = 0;
                bool prev_minor = false;

                for(auto &ch: s) {
                    if(ch == major) major_count++;
                    if(ch == minor) minor_count++;

                    if(minor_count > 0) { // there should be atleast one minor char for variance to be valid
                        ans = max(ans, major_count - minor_count);
                    }
                    else if(prev_minor) {
                        ans = max(ans, major_count - 1);
                    }

                    if(major_count - minor_count < 0) {
                        major_count = 0;
                        minor_count = 0;
                        prev_minor = true;
                    }
                }
            }
        }

        return ans;
    }
};